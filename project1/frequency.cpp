#include "frequency.hpp"

std::map<char, uint32_t> calculateCharFrequency(const std::string& text) {
	std::map<char, uint32_t> freq;

	for (uint32_t i = 0; i < text.size(); i++) {
		char c = text[i];

		if (!freq[c]) {
			freq[c] = 1;
		} else {
			freq[c]++;
		}
	}

	return freq;
}

std::map<uint32_t, uint32_t> calculateSymbolFrequency(std::vector<uint32_t> symbols) {
	std::map<uint32_t, uint32_t> freq;

	for (uint32_t i = 0; i < symbols.size(); i++) {
		uint32_t c = symbols[i];

		if (!freq[c]) {
			freq[c] = 1;
		} else {
			freq[c]++;
		}
	}

	return freq;
}

std::map<char, uint32_t> generateFrequencyMap() {
	std::map<char, uint32_t> literal = {
		{' ', 19},
		{'a', 7},
		{'b', 1},
		{'c', 2},
		{'d', 4},
		{'e', 10},
		{'f', 2},
		{'g', 2},
		{'h', 5},
		{'i', 6},
		{'j', 1},
		{'k', 1},
		{'l', 3},
		{'m', 2},
		{'n', 6},
		{'o', 6},
		{'p', 2},
		{'q', 1},
		{'r', 5},
		{'s', 5},
		{'t', 7},
		{'u', 2},
		{'v', 1},
		{'w', 2},
		{'x', 1},
		{'y', 2},
		{'z', 1}
	};

	return literal;
}

std::vector<std::vector<float>> generateEnglishWordsDigramFrequencyMap() {
	std::vector<std::vector<float>> literal = {
		{0.00003638, 0.00340615, 0.00387619, 0.00271496, 0.00032357, 0.00058875, 0.00219322, 0.00026901, 0.00211089, 0.00006223, 0.00077639, 0.00860919, 0.00260966, 0.00879108, 0.00006031, 0.00254169, 0.00007467, 0.00752933, 0.00436634, 0.01116810, 0.00124739, 0.00107028, 0.00070172, 0.00026996, 0.00102625, 0.00033793, 0.00138812 },
		{0.00225162, 0.00066438, 0.00006606, 0.00007850, 0.00238852, 0.00002776, 0.00001149, 0.00002968, 0.00221237, 0.00006223, 0.00000766, 0.00351624, 0.00006606, 0.00003925, 0.00208026, 0.00002393, 0, 0.00150587, 0.00057535, 0.00012732, 0.00137471, 0.00003063, 0.00002489, 9.6E-7, 0.00017136, 0, 0.00017423 },
		{0.00535908, 0.00000287, 0.00062513, 0.00001149, 0.00369334, 0, 9.6E-7, 0.00426678, 0.00279059, 0, 0.00242968, 0.00145704, 0.00000479, 0.00001436, 0.00614121, 0.00000479, 0.00006127, 0.00209653, 0.00041261, 0.00267954, 0.00189358, 0, 0.00000191, 0, 0.00048058, 0.00002489, 0.00176817 },
		{0.00159873, 0.00015030, 0.00008616, 0.00064523, 0.00661604, 0.00009190, 0.00040016, 0.00011201, 0.00493020, 0.00011296, 0.00000862, 0.00095732, 0.00020965, 0.00024220, 0.00167818, 0.00007946, 0.00000862, 0.00110858, 0.00142545, 0.00004404, 0.00099370, 0.00012732, 0.00016562, 9.6E-7, 0.00032645, 0.00000479, 0.01071242 },
		{0.00439123, 0.00072469, 0.00342817, 0.01136148, 0.00245170, 0.00121867, 0.00116697, 0.00037240, 0.00096977, 0.00011584, 0.00018189, 0.00470906, 0.00278006, 0.00982881, 0.00078692, 0.00183614, 0.00028528, 0.02011331, 0.01815367, 0.00402745, 0.00054472, 0.00113155, 0.00080606, 0.00148672, 0.00061173, 0.00013402, 0.01030460 },
		{0.00112389, 0.00002010, 0.00000766, 0.00001149, 0.00150299, 0.00112964, 0.00000574, 0.00001915, 0.00228991, 0.00000191, 9.6E-7, 0.00134216, 0.00000479, 0.00000766, 0.00150299, 0.00000862, 0, 0.00090371, 0.00019242, 0.00043367, 0.00120814, 0, 0.00000574, 0, 0.00028528, 0, 0.00024029 },
		{0.00181412, 0.00005361, 0.00000574, 0.00002106, 0.00335445, 0.00003542, 0.00080989, 0.00101189, 0.00207164, 0.00000383, 0.00000479, 0.00141492, 0.00017040, 0.00069693, 0.00102816, 0.00001723, 0, 0.00200942, 0.00103391, 0.00005840, 0.00096498, 0, 0.00005361, 0, 0.00037718, 0.00000383, 0.00876140 },
		{0.00310938, 0.00008807, 0.00002010, 0.00003255, 0.00484596, 0.00006414, 0.00000574, 0.00003255, 0.00312469, 0.00000670, 0.00001053, 0.00026805, 0.00023933, 0.00016945, 0.00308257, 0.00003446, 0.00000191, 0.00063662, 0.00040399, 0.00073618, 0.00077256, 9.6E-7, 0.00010531, 0, 0.00083957, 0, 0.00123877 },
		{0.00317926, 0.00118325, 0.00659785, 0.00241532, 0.00610196, 0.00156235, 0.00207451, 0.00004595, 0.00004021, 0.00002202, 0.00028815, 0.00429358, 0.00239809, 0.01963656, 0.00563383, 0.00149246, 0.00015317, 0.00206303, 0.00779738, 0.00584061, 0.00032070, 0.00231480, 0.00002489, 0.00022497, 0.00000862, 0.00237128, 0.00036570 },
		{0.00036187, 0, 9.6E-7, 0, 0.00030730, 0, 0, 0, 0.00013402, 0.00000383, 9.6E-7, 0, 0, 0.00000287, 0.00037336, 0, 0, 0, 0, 0, 0.00049302, 0, 0, 0, 0, 0, 0.00000479 },
		{0.00043271, 0.00008616, 0.00001149, 0.00002680, 0.00227172, 0.00004499, 0.00000766, 0.00007563, 0.00150874, 0.00000862, 0.00002585, 0.00038771, 0.00006606, 0.00027571, 0.00016562, 0.00004021, 0, 0.00009477, 0.00092190, 0.00005170, 0.00008999, 0.00000766, 0.00008041, 0, 0.00022306, 0, 0.00089414 },
		{0.00568840, 0.00014743, 0.00027762, 0.00071416, 0.00947748, 0.00024890, 0.00016849, 0.00006031, 0.00808170, 0.00000191, 0.00031304, 0.00485649, 0.00028911, 0.00021540, 0.00416339, 0.00024316, 0.00000574, 0.00005361, 0.00152501, 0.00096306, 0.00171360, 0.00027858, 0.00006510, 0.00000191, 0.00537536, 0.00000670, 0.00320798 },
		{0.00419881, 0.00123686, 0.00002393, 0.00001245, 0.00470236, 0.00007084, 0.00000287, 0.00001532, 0.00419498, 0.00000287, 0.00000862, 0.00010243, 0.00103486, 0.00021348, 0.00260296, 0.00219035, 0.00000383, 0.00003159, 0.00102529, 0.00001915, 0.00101476, 0.00001532, 0.00002106, 0, 0.00026422, 0, 0.00156618 },
		{0.00393555, 0.00021348, 0.00348752, 0.00399777, 0.00730914, 0.00083478, 0.01150221, 0.00029103, 0.00455493, 0.00013498, 0.00080415, 0.00038197, 0.00024699, 0.00104731, 0.00280112, 0.00029677, 0.00012924, 0.00029390, 0.00559937, 0.00722873, 0.00082234, 0.00052174, 0.00018093, 0.00002872, 0.00032453, 0.00008329, 0.00507667 },
		{0.00103391, 0.00105305, 0.00185720, 0.00147236, 0.00057631, 0.00056961, 0.00213865, 0.00013402, 0.00117942, 0.00003542, 0.00054759, 0.00383503, 0.00323862, 0.01079475, 0.00235022, 0.00224970, 0.00006414, 0.00730340, 0.00290834, 0.00266518, 0.00430603, 0.00145417, 0.00164181, 0.00038293, 0.00033698, 0.00014934, 0.00066151 },
		{0.00274560, 0.00004691, 0.00004212, 0.00002393, 0.00426678, 0.00003829, 0.00001245, 0.00186199, 0.00257136, 0.00000957, 0.00002585, 0.00188688, 0.00006127, 0.00006127, 0.00273315, 0.00133833, 0, 0.00344061, 0.00107890, 0.00096977, 0.00106646, 0, 0.00004404, 0, 0.00026135, 9.6E-7, 0.00069789 },
		{0.00000287, 0, 0, 0, 9.6E-7, 0, 0, 0, 0.00000670, 0, 0, 0, 0, 0, 0.00000191, 0, 0, 9.6E-7, 9.6E-7, 0.00000191, 0.00161787, 0, 0, 0, 0, 0, 0.00000479 },
		{0.00836028, 0.00075628, 0.00116985, 0.00157192, 0.01215223, 0.00038197, 0.00081947, 0.00024316, 0.00833635, 0.00004212, 0.00068448, 0.00069980, 0.00144173, 0.00113443, 0.00591050, 0.00065385, 0.00003638, 0.00146374, 0.00660168, 0.00233299, 0.00177009, 0.00045473, 0.00019338, 0.00000479, 0.00148576, 0.00002202, 0.00734648 },
		{0.00211089, 0.00013977, 0.00239043, 0.00007850, 0.00555916, 0.00015892, 0.00006701, 0.00354209, 0.00425625, 0.00001819, 0.00058301, 0.00126941, 0.00144268, 0.00077352, 0.00198261, 0.00206111, 0.00025178, 0.00007180, 0.00547779, 0.00988338, 0.00227938, 0.00001436, 0.00049398, 0, 0.00057918, 0.00000191, 0.03429219 },
		{0.00495701, 0.00017040, 0.00057822, 0.00004882, 0.01151274, 0.00020582, 0.00008233, 0.00308640, 0.01292000, 0.00000766, 0.00000479, 0.00111815, 0.00022976, 0.00018285, 0.00442857, 0.00008520, 0, 0.00459993, 0.00363207, 0.00188114, 0.00191751, 0.00000862, 0.00033602, 9.6E-7, 0.00159681, 0.00012349, 0.00577935 },
		{0.00117846, 0.00114113, 0.00124739, 0.00090850, 0.00110379, 0.00036857, 0.00074480, 0.00000766, 0.00110953, 0.00002010, 0.00009669, 0.00308927, 0.00204292, 0.00493499, 0.00024986, 0.00113155, 0.00000479, 0.00368186, 0.00387045, 0.00255030, 0.00001627, 0.00008616, 0.00000574, 0.00008807, 0.00002106, 0.00010722, 0.00009382 },
		{0.00136131, 0, 9.6E-7, 0.00000191, 0.00499147, 0, 9.6E-7, 0, 0.00195198, 0, 0, 0.00000287, 0, 0.00000574, 0.00075150, 0, 0, 0.00002298, 0.00000862, 0.00000287, 0.00012062, 0.00002106, 0, 0, 0.00003829, 0.00000191, 0.00002298 },
		{0.00157671, 0.00008616, 0.00002393, 0.00010531, 0.00126941, 0.00004691, 0.00001149, 0.00052748, 0.00121867, 9.6E-7, 0.00006031, 0.00023837, 0.00003351, 0.00039346, 0.00097455, 0.00003925, 0, 0.00027954, 0.00036857, 0.00003638, 0.00001915, 0, 0.00001245, 0, 0.00004021, 0.00000766, 0.00030539 },
		{0.00017232, 0.00000479, 0.00019146, 0, 0.00041069, 0.00000957, 0.00000287, 0.00006606, 0.00044994, 0, 0, 0.00001627, 0.00000574, 0.00000287, 0.00011775, 0.00036665, 0.00000287, 0, 0.00001340, 0.00031687, 0.00010148, 0.00000479, 0.00001053, 0.00000862, 0.00007276, 0, 0.00025369 },
		{0.00037718, 0.00012254, 0.00032166, 0.00017615, 0.00055237, 0.00005074, 0.00010531, 0.00004212, 0.00051600, 0.00000670, 0.00000862, 0.00035229, 0.00039537, 0.00029485, 0.00027379, 0.00045377, 0, 0.00025178, 0.00079649, 0.00017806, 0.00003063, 0.00001245, 0.00010052, 0.00002680, 0, 0.00005265, 0.00966990 },
		{0.00053036, 0.00000191, 0.00000191, 9.6E-7, 0.00187826, 0, 0.00000191, 0.00000479, 0.00072661, 9.6E-7, 0.00000383, 0.00011967, 0.00000766, 9.6E-7, 0.00022784, 0.00000957, 0.00000287, 0, 9.6E-7, 0.00000383, 0.00003063, 0.00000574, 0.00000383, 0, 0.00006988, 0.00023837, 0.00005265 },
		{0.00626183, 0.00601102, 0.00988146, 0.00640639, 0.00430220, 0.00450036, 0.00343965, 0.00375270, 0.00419306, 0.00100136, 0.00092286, 0.00321947, 0.00555629, 0.00236841, 0.00283654, 0.00808745, 0.00055237, 0.00651361, 0.01158932, 0.00529398, 0.00317065, 0.00174711, 0.00259625, 0.00007563, 0.00035229, 0.00025369, 0 },
	};

	return literal;
}

std::vector<std::vector<float>> generatePlaintextDictionaryDigramFrequencyMatrix() {
	std::vector<std::vector<float>> literal = {
		{0, 0.005188, 0.001995, 0.003192, 0, 0.000399, 0.002394, 0.000399, 0.002394, 0, 0.000399, 0.009577, 0.001995, 0.011173, 0, 0.001995, 0, 0.005587, 0.005587, 0.009976, 0.000399, 0.000798, 0.000399, 0, 0, 0.000798, 0.000399},
		{0.002793, 0.000798, 0, 0, 0, 0, 0, 0, 0.003990, 0.000399, 0, 0.002394, 0, 0.000399, 0.001596, 0, 0, 0.000798, 0.000399, 0, 0.000798, 0, 0, 0, 0.000798, 0, 0},
		{0.007981, 0, 0, 0, 0.002394, 0, 0, 0.003192, 0.003591, 0, 0.001197, 0.002394, 0, 0, 0.007183, 0, 0, 0.003192, 0.000399, 0.001197, 0.003192, 0, 0, 0, 0.000399, 0, 0.001596},
		{0.001995, 0, 0, 0, 0.009577, 0, 0.001197, 0.000399, 0.003192, 0, 0, 0.001197, 0, 0, 0.002793, 0, 0, 0.001995, 0.002394, 0, 0.001995, 0, 0, 0, 0.001197, 0, 0.009976},
		{0.002793, 0.000399, 0.003591, 0.009178, 0.001197, 0.002793, 0.001197, 0, 0.001197, 0.000798, 0, 0.004389, 0.002793, 0.008380, 0.000399, 0.001197, 0, 0.019154, 0.019154, 0.005587, 0.000798, 0.001197, 0.000798, 0.001995, 0.000399, 0.000399, 0.013567},
		{0.000399, 0, 0, 0, 0.000798, 0.000798, 0, 0, 0.003192, 0, 0, 0.001197, 0, 0, 0.002793, 0, 0, 0, 0, 0.000798, 0.001995, 0, 0, 0, 0.000399, 0, 0.000399},
		{0.003591, 0, 0.000399, 0, 0.004389, 0, 0.001197, 0.000798, 0.001995, 0, 0, 0.000798, 0.000399, 0.000798, 0.001995, 0, 0, 0.001596, 0.000399, 0, 0.001197, 0, 0, 0, 0.001596, 0, 0.008380},
		{0.001596, 0.000399, 0, 0, 0.003591, 0.000399, 0, 0, 0.003591, 0, 0, 0.000798, 0.001197, 0, 0.002793, 0, 0, 0.001197, 0, 0.000798, 0.002394, 0, 0, 0, 0.001596, 0, 0.001197},
		{0.001596, 0.001197, 0.005188, 0.003591, 0.004389, 0.001596, 0.003192, 0, 0, 0, 0, 0.004789, 0.003591, 0.014366, 0.006784, 0.002394, 0, 0.002394, 0.009178, 0.005587, 0.000399, 0.001197, 0, 0, 0, 0.003990, 0.000798},
		{0.001197, 0, 0, 0, 0.000798, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0.000399, 0, 0, 0, 0, 0, 0.001197, 0, 0, 0, 0, 0, 0},
		{0.000798, 0, 0, 0, 0.000798, 0, 0, 0, 0.000399, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0.000399, 0, 0.000399, 0, 0, 0, 0.000399, 0, 0.000798},
		{0.003990, 0, 0.000798, 0.001596, 0.007981, 0, 0, 0, 0.009976, 0, 0, 0.006385, 0.000798, 0.000399, 0.006784, 0.000399, 0, 0, 0.001596, 0.001995, 0.000798, 0.000399, 0, 0, 0.004789, 0, 0.004389},
		{0.005188, 0.001197, 0, 0, 0.006784, 0, 0, 0, 0.005587, 0, 0, 0.000399, 0, 0.000399, 0.002793, 0.001197, 0, 0, 0.001596, 0, 0.001596, 0, 0, 0, 0, 0, 0.002793},
		{0.003591, 0, 0.001596, 0.005587, 0.007183, 0.000399, 0.009178, 0, 0.004389, 0, 0.000798, 0, 0, 0.001596, 0.001995, 0, 0, 0, 0.006784, 0.006385, 0.001995, 0.000798, 0.000399, 0, 0.000399, 0, 0.004389},
		{0.000798, 0.000399, 0.001596, 0.002394, 0.001197, 0, 0.002793, 0.000399, 0.000798, 0, 0, 0.004389, 0.001995, 0.014765, 0.002793, 0.002793, 0, 0.009976, 0.001995, 0.002793, 0.002793, 0.002394, 0.001596, 0.000798, 0, 0, 0.001596},
		{0.002793, 0, 0, 0, 0.006385, 0, 0, 0.001197, 0.001197, 0, 0, 0.000798, 0, 0, 0.002394, 0.001995, 0, 0.004389, 0.001197, 0.001596, 0.000798, 0, 0, 0, 0, 0.000399, 0.001197},
		{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0.000798, 0, 0, 0, 0, 0, 0},
		{0.004389, 0, 0.001995, 0.001596, 0.017558, 0, 0.001197, 0.000399, 0.007981, 0, 0.000399, 0.000798, 0.001596, 0.000399, 0.006784, 0, 0, 0.000798, 0.009976, 0.001995, 0.001197, 0, 0, 0, 0.001995, 0, 0.004789},
		{0.003192, 0, 0.003591, 0.000399, 0.005188, 0, 0, 0.003591, 0.002793, 0.000399, 0.000399, 0.000798, 0.002793, 0.000399, 0.001596, 0.001197, 0, 0, 0.005188, 0.009178, 0.000399, 0, 0, 0, 0, 0, 0.036313},
		{0.005188, 0, 0, 0.000399, 0.009577, 0, 0, 0.003990, 0.011971, 0, 0, 0.000399, 0, 0, 0.003591, 0.000399, 0, 0.001995, 0.003990, 0.001197, 0.001995, 0, 0, 0, 0.001197, 0, 0.005986},
		{0.000798, 0.000798, 0.001197, 0.000798, 0.001995, 0.000399, 0.000399, 0, 0.000399, 0, 0, 0.005587, 0.002793, 0.002394, 0.000399, 0.000798, 0, 0.001995, 0.004389, 0.001995, 0, 0, 0, 0, 0, 0, 0},
		{0.000399, 0, 0, 0, 0.005587, 0, 0, 0, 0.000399, 0, 0, 0, 0, 0, 0.000399, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		{0.000399, 0.000399, 0, 0, 0.000399, 0, 0, 0, 0, 0, 0, 0.000399, 0, 0.000399, 0.000798, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0.000399},
		{0, 0, 0, 0, 0, 0, 0.000399, 0, 0, 0, 0, 0, 0, 0, 0, 0.001197, 0, 0, 0, 0.000399, 0, 0, 0, 0, 0.000399, 0, 0.000399},
		{0, 0, 0.000798, 0.000399, 0, 0, 0.000798, 0, 0.002394, 0, 0, 0.000399, 0.000399, 0, 0.000399, 0, 0, 0.000399, 0.000399, 0.000399, 0, 0, 0, 0, 0, 0, 0.008779},
		{0.001197, 0, 0.000399, 0, 0.002793, 0, 0, 0, 0.001197, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		{0.008380, 0.004389, 0.014765, 0.008779, 0.002793, 0.005986, 0.005587, 0.007183, 0.003591, 0.001995, 0.000798, 0.005188, 0.009178, 0.001596, 0.003591, 0.010774, 0.000798, 0.010375, 0.002394, 0, 0, 0, 0, 0, 0, 0, 0},
	};

	return literal;
}

std::vector<std::vector<float>> generateTestOneDigramFrequencyMatrix(uint32_t index) {
	std::vector<std::vector<float>> literal;
	switch (index) {
		case 1: {
			literal = {
				{0, 3, 2, 2, 0, 0, 1, 0, 0, 0, 1, 8, 1, 6, 0, 0, 0, 4, 2, 3, 0, 0, 0, 0, 0, 0, 1},
				{1, 1, 0, 0, 0, 0, 0, 0, 2, 0, 0, 1, 0, 0, 3, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0},
				{5, 0, 0, 0, 2, 0, 0, 4, 1, 0, 1, 2, 0, 0, 2, 0, 0, 1, 1, 0, 1, 0, 0, 0, 0, 0, 1},
				{1, 0, 0, 0, 4, 0, 0, 0, 1, 0, 0, 0, 0, 0, 3, 0, 0, 2, 0, 0, 1, 0, 0, 0, 0, 0, 3},
				{1, 1, 0, 3, 0, 2, 1, 0, 1, 0, 0, 3, 0, 4, 0, 1, 0, 11, 10, 3, 1, 0, 1, 0, 0, 1, 8},
				{0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 2, 0, 0, 1, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0},
				{1, 0, 0, 0, 4, 0, 1, 0, 1, 0, 0, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 6},
				{0, 0, 0, 0, 2, 0, 0, 0, 2, 0, 0, 0, 0, 0, 3, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 2},
				{1, 1, 4, 0, 1, 0, 3, 0, 0, 0, 0, 2, 2, 7, 3, 3, 0, 1, 2, 2, 0, 0, 0, 0, 0, 2, 0},
				{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
				{0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 1},
				{2, 0, 0, 1, 4, 0, 0, 0, 5, 0, 0, 3, 0, 1, 2, 0, 0, 0, 1, 2, 1, 0, 0, 0, 0, 0, 5},
				{5, 0, 0, 0, 4, 0, 0, 0, 2, 0, 0, 0, 0, 0, 2, 1, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 2},
				{3, 0, 1, 3, 4, 0, 5, 0, 3, 0, 1, 0, 0, 0, 0, 0, 0, 0, 6, 2, 2, 0, 0, 0, 0, 0, 0},
				{1, 0, 1, 0, 1, 0, 2, 0, 0, 0, 0, 2, 2, 8, 1, 0, 0, 6, 1, 0, 1, 3, 2, 0, 0, 0, 0},
				{1, 0, 0, 0, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 2, 0, 2, 0, 1, 0, 0, 0, 0, 0, 0, 0},
				{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0},
				{2, 0, 1, 1, 12, 0, 1, 0, 3, 0, 1, 1, 0, 1, 5, 0, 0, 0, 7, 1, 0, 0, 0, 0, 0, 0, 2},
				{2, 0, 2, 0, 1, 0, 0, 2, 3, 0, 0, 0, 2, 0, 1, 0, 0, 0, 3, 4, 1, 0, 0, 0, 0, 0, 18},
				{3, 0, 0, 1, 2, 0, 0, 3, 7, 0, 0, 0, 0, 0, 0, 0, 0, 1, 3, 0, 1, 0, 0, 0, 0, 0, 1},
				{1, 0, 1, 1, 1, 0, 0, 0, 1, 0, 0, 3, 1, 0, 1, 0, 0, 1, 0, 3, 0, 0, 0, 0, 0, 0, 0},
				{0, 0, 0, 0, 3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
				{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
				{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
				{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2},
				{0, 0, 1, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
				{3, 3, 7, 3, 0, 4, 3, 3, 1, 1, 0, 0, 9, 1, 1, 4, 1, 8, 1, 0, 0, 0, 0, 0, 0, 0, 0}
			};

			break;
		}

		case 2: {
			literal = {
				{0, 3, 1, 0, 0, 1, 3, 0, 1, 0, 0, 4, 1, 3, 0, 2, 0, 3, 2, 3, 0, 0, 0, 0, 0, 1, 0},
				{1, 0, 0, 0, 0, 0, 0, 0, 2, 1, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0},
				{4, 0, 0, 0, 1, 0, 0, 2, 2, 0, 1, 2, 0, 0, 3, 0, 0, 4, 0, 1, 0, 0, 0, 0, 1, 0, 2},
				{0, 0, 0, 0, 4, 0, 1, 0, 3, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 2, 0, 0, 0, 1, 0, 7},
				{0, 0, 4, 7, 1, 0, 0, 0, 0, 1, 0, 2, 2, 5, 0, 0, 0, 9, 3, 4, 0, 0, 1, 0, 0, 0, 6},
				{0, 0, 0, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0},
				{1, 0, 0, 0, 1, 0, 0, 0, 2, 0, 0, 0, 0, 1, 3, 0, 0, 3, 0, 0, 0, 0, 0, 0, 0, 0, 4},
				{0, 0, 0, 0, 3, 0, 0, 0, 1, 0, 0, 1, 2, 0, 1, 0, 0, 1, 0, 0, 1, 0, 0, 0, 1, 0, 0},
				{0, 0, 4, 3, 1, 2, 1, 0, 0, 0, 0, 5, 3, 5, 2, 1, 0, 2, 6, 2, 1, 0, 0, 0, 0, 5, 1},
				{0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0},
				{2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0},
				{2, 0, 0, 1, 2, 0, 0, 0, 10, 0, 0, 5, 1, 0, 4, 0, 0, 0, 0, 1, 0, 0, 0, 0, 4, 0, 0},
				{0, 2, 0, 0, 5, 0, 0, 0, 6, 0, 0, 1, 0, 0, 2, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 1},
				{2, 0, 0, 2, 2, 0, 5, 0, 2, 0, 0, 0, 0, 1, 2, 0, 0, 0, 2, 3, 1, 0, 0, 0, 1, 0, 4},
				{0, 0, 0, 2, 0, 0, 1, 0, 0, 0, 0, 3, 1, 9, 2, 1, 0, 5, 2, 1, 2, 1, 0, 0, 0, 0, 1},
				{1, 0, 0, 0, 3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 3, 0, 0, 0, 1, 2, 0, 0, 0, 0, 0, 0, 1},
				{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
				{2, 0, 0, 1, 9, 0, 0, 1, 5, 0, 0, 0, 0, 0, 3, 0, 0, 1, 6, 0, 2, 0, 0, 0, 1, 0, 3},
				{2, 0, 2, 0, 2, 0, 0, 3, 0, 0, 0, 0, 1, 1, 2, 0, 0, 0, 1, 5, 0, 0, 0, 0, 0, 0, 14},
				{2, 0, 0, 0, 5, 0, 0, 2, 4, 0, 0, 0, 0, 0, 1, 1, 0, 0, 2, 1, 1, 0, 0, 0, 1, 0, 5},
				{0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 1, 3, 1, 0, 1, 0, 2, 2, 0, 0, 0, 0, 0, 0, 0, 0},
				{0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
				{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
				{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
				{0, 0, 2, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 6},
				{1, 0, 0, 0, 3, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
				{7, 0, 9, 4, 0, 3, 4, 3, 0, 0, 2, 4, 5, 1, 2, 5, 0, 4, 2, 0, 0, 0, 0, 0, 0, 0, 0}
			};

			break;
		}

		case 3: {
			literal = {
				{0, 2, 1, 0, 0, 0, 1, 0, 3, 0, 0, 4, 0, 5, 0, 1, 0, 3, 4, 6, 0, 2, 0, 0, 0, 1, 0},
				{2, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0},
				{2, 0, 0, 0, 1, 0, 0, 0, 4, 0, 0, 0, 0, 0, 3, 0, 0, 1, 0, 0, 5, 0, 0, 0, 0, 0, 1},
				{1, 0, 0, 0, 4, 0, 0, 0, 1, 0, 0, 1, 0, 0, 1, 0, 0, 1, 1, 0, 1, 0, 0, 0, 0, 0, 1},
				{0, 0, 2, 1, 1, 1, 1, 0, 1, 1, 0, 0, 3, 5, 0, 0, 0, 10, 13, 2, 0, 2, 0, 1, 1, 0, 7},
				{0, 0, 0, 0, 2, 1, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1},
				{3, 0, 1, 0, 0, 0, 2, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0, 1},
				{2, 0, 0, 0, 1, 0, 0, 0, 2, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 3, 0, 0, 0, 1, 0, 0},
				{1, 2, 3, 2, 2, 0, 2, 0, 0, 0, 0, 2, 1, 5, 7, 2, 0, 1, 6, 5, 0, 1, 0, 0, 0, 1, 0},
				{2, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
				{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
				{2, 0, 1, 1, 7, 0, 0, 0, 4, 0, 0, 2, 0, 0, 1, 0, 0, 0, 0, 2, 0, 1, 0, 0, 4, 0, 1},
				{3, 1, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 1},
				{2, 0, 0, 1, 4, 0, 1, 0, 4, 0, 0, 0, 0, 1, 1, 0, 0, 0, 3, 3, 1, 1, 0, 0, 0, 0, 4},
				{1, 0, 1, 2, 0, 0, 0, 1, 1, 0, 0, 1, 0, 8, 1, 2, 0, 0, 1, 3, 1, 1, 1, 1, 0, 0, 0},
				{1, 0, 0, 0, 2, 0, 0, 2, 1, 0, 0, 1, 0, 0, 1, 0, 0, 3, 1, 0, 1, 0, 0, 0, 0, 1, 2},
				{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
				{0, 0, 1, 1, 7, 0, 0, 0, 4, 0, 0, 0, 1, 0, 1, 0, 0, 0, 7, 1, 0, 0, 0, 0, 0, 0, 1},
				{1, 0, 1, 0, 4, 0, 0, 1, 3, 0, 0, 1, 1, 0, 0, 2, 0, 0, 6, 5, 0, 0, 0, 0, 0, 0, 22},
				{4, 0, 0, 0, 5, 0, 0, 1, 7, 0, 0, 0, 0, 0, 2, 0, 0, 1, 2, 1, 1, 0, 0, 0, 2, 0, 3},
				{0, 1, 0, 0, 2, 1, 1, 0, 0, 0, 0, 5, 2, 0, 0, 1, 0, 0, 3, 1, 0, 0, 0, 0, 0, 0, 0},
				{0, 0, 0, 0, 6, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
				{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
				{0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
				{0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 8},
				{2, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
				{4, 1, 6, 4, 1, 4, 2, 5, 3, 3, 0, 3, 3, 1, 3, 7, 0, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0}
			};
			break;
		}
		case 4: {
			literal = {
				{0, 1, 0, 3, 0, 0, 0, 0, 1, 0, 0, 2, 1, 9, 0, 0, 0, 2, 3, 7, 1, 0, 1, 0, 0, 0, 0},
				{1, 0, 0, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0},
				{5, 0, 0, 0, 0, 0, 0, 2, 2, 0, 0, 1, 0, 0, 3, 0, 0, 0, 0, 2, 1, 0, 0, 0, 0, 0, 0},
				{1, 0, 0, 0, 6, 0, 2, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 2, 3, 0, 1, 0, 0, 0, 1, 0, 7},
				{3, 0, 1, 4, 0, 1, 0, 0, 1, 0, 0, 3, 1, 3, 1, 0, 0, 7, 15, 2, 1, 0, 0, 2, 0, 0, 9},
				{1, 0, 0, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0},
				{0, 0, 0, 0, 6, 0, 0, 1, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 5},
				{1, 1, 0, 0, 1, 1, 0, 0, 4, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0},
				{0, 0, 1, 4, 6, 2, 1, 0, 0, 0, 0, 2, 2, 9, 3, 0, 0, 2, 4, 3, 0, 2, 0, 0, 0, 0, 0},
				{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0},
				{0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
				{3, 0, 1, 1, 5, 0, 0, 0, 4, 0, 0, 3, 0, 0, 2, 0, 0, 0, 0, 0, 1, 0, 0, 0, 2, 0, 3},
				{3, 0, 0, 0, 2, 0, 0, 0, 3, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1},
				{2, 0, 2, 4, 5, 0, 7, 0, 1, 0, 0, 0, 0, 2, 0, 0, 0, 0, 2, 4, 0, 0, 1, 0, 0, 0, 2},
				{0, 0, 0, 1, 1, 0, 1, 0, 0, 0, 0, 2, 1, 5, 2, 2, 0, 4, 0, 2, 2, 0, 0, 1, 0, 0, 1},
				{2, 0, 0, 0, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 3, 1, 0, 1, 0, 0, 0, 0, 0, 0},
				{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0},
				{2, 0, 1, 0, 4, 0, 1, 0, 4, 0, 0, 1, 2, 0, 3, 0, 0, 1, 3, 3, 1, 0, 0, 0, 1, 0, 1},
				{1, 0, 2, 0, 2, 0, 0, 3, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 8, 0, 0, 0, 0, 0, 0, 19},
				{2, 0, 0, 0, 7, 0, 0, 2, 10, 0, 0, 1, 0, 0, 3, 0, 0, 1, 1, 1, 2, 0, 0, 0, 0, 0, 3},
				{1, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 4, 1, 3, 0, 0, 0, 2, 5, 0, 0, 0, 0, 0, 0, 0, 0},
				{0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
				{0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
				{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0},
				{0, 0, 0, 1, 0, 0, 1, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 2},
				{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
				{3, 2, 7, 5, 2, 3, 2, 3, 4, 1, 0, 2, 3, 1, 2, 8, 1, 2, 2, 0, 0, 0, 0, 0, 0, 0, 0}
			};
			break;
		}
		case 5: {
			std::vector<std::vector<float>> literal = {
				{0, 4, 1, 3, 0, 0, 1, 1, 1, 0, 0, 6, 2, 5, 0, 2, 0, 2, 3, 6, 0, 0, 0, 0, 0, 0, 0},
				{2, 0, 0, 0, 0, 0, 0, 0, 3, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 1, 0, 0, 0, 1, 0, 0},
				{4, 0, 0, 0, 2, 0, 0, 0, 0, 0, 1, 1, 0, 0, 7, 0, 0, 2, 0, 0, 1, 0, 0, 0, 0, 0, 0},
				{2, 0, 0, 0, 6, 0, 0, 1, 2, 0, 0, 1, 0, 0, 2, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 7},
				{3, 0, 2, 8, 1, 3, 1, 0, 0, 0, 0, 3, 1, 4, 0, 2, 0, 11, 7, 3, 0, 1, 0, 2, 0, 0, 4},
				{0, 0, 0, 0, 0, 1, 0, 0, 2, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0},
				{4, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 1, 1, 0, 2, 0, 0, 0, 1, 0, 5},
				{1, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 1, 0, 2, 0, 0, 1, 0, 1, 1, 0, 0, 0, 1, 0, 0},
				{2, 0, 1, 0, 1, 0, 1, 0, 0, 0, 0, 1, 1, 10, 2, 0, 0, 0, 5, 2, 0, 0, 0, 0, 0, 2, 0},
				{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
				{0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
				{1, 0, 0, 0, 2, 0, 0, 0, 2, 0, 0, 3, 1, 0, 8, 1, 0, 0, 3, 0, 0, 0, 0, 0, 2, 0, 2},
				{2, 0, 0, 0, 4, 0, 0, 0, 3, 0, 0, 0, 0, 0, 2, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 2},
				{0, 0, 1, 4, 3, 1, 5, 0, 1, 0, 1, 0, 0, 0, 2, 0, 0, 0, 4, 4, 1, 1, 0, 0, 0, 0, 1},
				{0, 1, 2, 1, 1, 0, 3, 0, 1, 0, 0, 3, 1, 7, 1, 2, 0, 10, 1, 1, 1, 1, 1, 0, 0, 0, 0},
				{2, 0, 0, 0, 3, 0, 0, 1, 2, 0, 0, 1, 0, 0, 0, 2, 0, 3, 0, 1, 0, 0, 0, 0, 0, 0, 0},
				{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
				{5, 0, 2, 1, 12, 0, 1, 0, 4, 0, 0, 0, 1, 0, 5, 0, 0, 0, 2, 0, 0, 0, 0, 0, 3, 0, 5},
				{2, 0, 2, 1, 4, 0, 0, 0, 1, 0, 0, 0, 3, 0, 1, 1, 0, 0, 3, 1, 0, 0, 0, 0, 0, 0, 17},
				{2, 0, 0, 0, 5, 0, 0, 2, 2, 0, 0, 0, 0, 0, 3, 0, 0, 2, 2, 0, 0, 0, 0, 0, 0, 0, 3},
				{0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 2, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0},
				{1, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
				{0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
				{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
				{0, 0, 0, 0, 0, 0, 1, 0, 2, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 4},
				{0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
				{4, 3, 7, 5, 4, 1, 2, 4, 1, 0, 0, 4, 3, 0, 1, 3, 0, 8, 1, 0, 0, 0, 0, 0, 0, 0, 0}
			};
			break;
		}
	}

	return literal;
}
