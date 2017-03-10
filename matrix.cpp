#include "matrix.hpp"

// BEGIN: DIGRAM_FREQ_MATRIX
DigramFreqMatrix::DigramFreqMatrix(uint32_t rowCount, uint32_t columnCount) : matrix(rowCount, std::vector<uint32_t>(columnCount, 0)), rows(rowCount), columns(columnCount) {}

void DigramFreqMatrix::swapRow(uint32_t a, uint32_t b) {
	matrix[a].swap(matrix[b]);
}

void DigramFreqMatrix::swapColumn(uint32_t a, uint32_t b) {
	for (std::vector<std::vector<uint32_t>>::iterator outer = matrix.begin(); outer != matrix.end(); outer++) {
		std::vector<uint32_t>::iterator aIter = outer -> begin() + a;
		std::vector<uint32_t>::iterator bIter = outer -> begin() + b;

		std::iter_swap(aIter, bIter);
	}
}

std::vector<uint32_t> DigramFreqMatrix::getRow(uint32_t index) {
	return matrix[index];
}

std::vector<uint32_t> DigramFreqMatrix::getColumn(uint32_t index) {
	std::vector<uint32_t> v;

	for (std::vector<std::vector<uint32_t>>::iterator outer = matrix.begin(); outer != matrix.end(); outer++) {
		v.push_back((*outer)[index]);
	}

	return v;
}

void DigramFreqMatrix::printMatrix() {
	for (std::vector<std::vector<uint32_t>>::iterator outer = matrix.begin(); outer != matrix.end(); outer++) {
		for (std::vector<uint32_t>::iterator inner = outer -> begin(); inner != outer -> end(); inner++) {
			std::cout << *inner << ' ';
		}
		std::cout << std::endl;
	}
}

std::vector<uint32_t>& DigramFreqMatrix::operator[](const uint32_t index) {
	return matrix[index];
}

uint32_t DigramFreqMatrix::size() {
	return rows == columns ? rows : 0;
}

void DigramFreqMatrix::clearMatrix() {
	for (std::vector<std::vector<uint32_t>>::iterator outer = matrix.begin(); outer != matrix.end(); outer++) {
		std::fill(outer -> begin(), outer -> end(), 0);
	}
}
// END: DIGRAM_FREQ_MATRIX


// BEGIN: D_CIPHER_MATRIX
DCipherMatrix::DCipherMatrix(uint32_t rowCount = 116, uint32_t columnCount = 116) : DigramFreqMatrix(rowCount, columnCount) {}

void DCipherMatrix::populateMatrix(const std::string& text) {
	std::vector<std::string> splitVector = split(text, ',');
	std::vector<uint32_t> numVector = stringToUnsignedInt(splitVector);

	for (uint32_t i = 0; i < numVector.size() - 1; i++) {
		uint32_t row = numVector[i];
		uint32_t column = numVector[i + 1];

		matrix[row][column]++;
	}
}
// END: D_CIPHER_MATRIX


// BEGIN: D_PLAIN_MATRIX
DPlainMatrix::DPlainMatrix(uint32_t rowCount = 27, uint32_t columnCount = 27) : DigramFreqMatrix(rowCount, columnCount) {}

void DPlainMatrix::populateMatrix() {
	std::vector<uint32_t> row;

	for (uint32_t i = 0; i < cipherMatrix -> size(); i++) {
		row = (*cipherMatrix)[i];

		for (uint32_t j = 0; j < row.size(); j++) {
			uint32_t xIndex = getIndexForChar((*key)[i]);
			uint32_t yIndex = getIndexForChar((*key)[j]);

			matrix[xIndex][yIndex] += row[j];
		}
	}
}

// update matrix based on updated key and if needed, ciphertext matrix
void DPlainMatrix::updateMatrix(uint32_t a, uint32_t b) {
	clearMatrix();

	char x = (*key)[a];
	char y = (*key)[b];

	int xCount = getFrequencyForChar(x);
	int yCount = getFrequencyForChar(y);

	if ((xCount == -1) || (yCount == -1)) {
		throw std::runtime_error("Could not find char in frequencyMap");
	}

	if ((xCount == 1) && (yCount == 1)) {
		// both plaintexts only have one corresponding ciphertext symbol
		swapColumn(a, b);
		swapRow(a, b);
	} else {
		// one or more have more than one ciphertext symbols
		populateMatrix();
	}
}

uint32_t DPlainMatrix::computeScore() {
	EMatrix expected = *expectedMatrix;

	uint32_t score = 0;

	for (uint32_t outer = 0; outer < rows; outer++) {
		for (uint32_t inner = 0; inner < columns; outer++) {
			int local = matrix[outer][inner] - expected[outer][inner];

			if (local < 0) {
				local *= -1;
			}

			score += local;
		}
	}

	return score;
}

void DPlainMatrix::setKey(std::vector<char>* k) {
	key = k;
}

void DPlainMatrix::setFrequencyMap(std::map<char, uint32_t>* fm) {
	frequencyMap = fm;
}

void DPlainMatrix::setCipherMatrix(DCipherMatrix* dc) {
	cipherMatrix = dc;
}

void DPlainMatrix::setExpectedMatrix(EMatrix* em) {
	expectedMatrix = em;
}

// swap index a and b of the key
void DPlainMatrix::updateKey(uint32_t a, uint32_t b) {
	std::vector<char>::iterator aIter = key -> begin() + a;
	std::vector<char>::iterator bIter = key -> begin() + b;
	std::swap(*aIter, *bIter);
}

int DPlainMatrix::getFrequencyForChar(char x) {
	std::map<char, uint32_t>::iterator it;
	it = frequencyMap -> find(x);

	return it == frequencyMap -> end() ? -1 : it -> second;
}
// END: D_PLAIN_MATRIX


// BEGIN: E_MATRIX
EMatrix::EMatrix(uint32_t rowCount, uint32_t columnCount) : DigramFreqMatrix(rowCount, columnCount) {}
// END: E_MATRIX

