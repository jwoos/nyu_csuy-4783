#include "server.h"


static int fd;
static int clientDescriptor;
static struct sockaddr_in clientAddr;
static fd_set descriptors;

static void cleanup(void) {
	if (fd > 0) {
		if (shutdown(fd, SHUT_RDWR) < 0) {
			perror("shutdown");
		}

		if (close(fd) < 0) {
			perror("close");
		}
	}

	if (clientDescriptor > 0) {
		if (shutdown(clientDescriptor, SHUT_RDWR) < 0) {
			perror("shutdown");
		}

		if (close(clientDescriptor) < 0) {
			perror("close");
		}
	}
}

// create a TCP socket using IPv4
static void initSocket(void) {
	fd = socket(AF_INET, SOCK_STREAM, 0);
	if (fd < 0) {
		perror("socket");
		exit(EXIT_FAILURE);
	}
}

// bind to a port
static void initBind(int port) {
	struct sockaddr_in addr;
	memset(&addr, 0, sizeof(struct sockaddr_in));
	addr.sin_family = AF_INET;
	addr.sin_port = htons(port);
	struct in_addr ip;
	memset(&ip, 0, sizeof(struct in_addr));
	ip.s_addr = htonl(INADDR_ANY);
	addr.sin_addr = ip;

	if (bind(fd, (struct sockaddr*)&addr, sizeof(addr)) < 0) {
		perror("bind");
		exit(EXIT_FAILURE);
	}
}

// listen with no backlog
static void initListen(void) {
	if (listen(fd, 1) < 0) {
		perror("listen");
		exit(EXIT_FAILURE);
	}
}

static void initAccept(void) {
	// connect to a client
	println("Waiting to connect to client");

	unsigned int clientAddrSize;
	clientDescriptor = accept(fd, (struct sockaddr*)&clientAddr, &clientAddrSize);
	if (clientDescriptor < 0) {
		perror("accept");
		exit(EXIT_FAILURE);
	}

	println("Connected to client: %s:%d", inet_ntoa(clientAddr.sin_addr), ntohs(clientAddr.sin_port));
	println("");
}

static int initSelect(void) {
	// set up fd_set
	FD_ZERO(&descriptors);

	FD_SET(STDIN_FILENO, &descriptors);
	FD_SET(clientDescriptor, &descriptors);

	// the fd of the socket will always be greater than stdin
	int selectStatus = select(FD_SETSIZE, &descriptors, NULL, NULL, NULL);
	if (selectStatus < 0) {
		perror("select");
		exit(EXIT_FAILURE);
	}

	return selectStatus;
}

void server(int port) {
	// register cleanup
	atexit(cleanup);

	println("server: %d", port);

	initSocket();

	initBind(port);

	initListen();


	// don't die while waiting for a new connection
	while (true) {
		initAccept();

		char buffer[BUFFER_SIZE];

		// set up fd_set each time
		while (true) {
			fflush(stdin);
			memset(&buffer, 0, sizeof(char) * BUFFER_SIZE);

			int selectStatus = initSelect();
			if (selectStatus) {
				int n;

				if (FD_ISSET(STDIN_FILENO, &descriptors)) {
					if (fgets(buffer, READ_SIZE, stdin) == NULL) {
						perror("getline");
						continue;
					}

					printf("[you] %s", buffer);

					n = write(clientDescriptor, buffer, strlen(buffer));
					if (n < 0) {
						perror("write");
						continue;
					}
				}

				if (FD_ISSET(clientDescriptor, &descriptors)) {
					n = read(clientDescriptor, buffer, READ_SIZE);
					if (n < 0) {
						perror("read");
						continue;
					} else if (n == 0) {
						println("Connection closed");
						println("");
						break;
					}
					buffer[n] = '\0';

					printf("[%s:%d] %s", inet_ntoa(clientAddr.sin_addr), ntohs(clientAddr.sin_port), buffer);
				}
			}
		}
	}
}
