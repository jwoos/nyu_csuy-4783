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
		{0.0182, 1.7031, 1.9381, 1.3575, 0.1618, 0.2944, 1.0966, 0.1345, 1.0554, 0.0311, 0.3882, 4.3046, 1.3048, 4.3955, 0.0302, 1.2708, 0.0373, 3.7647, 2.1832, 5.5841, 0.6237, 0.5351, 0.3509, 0.1350, 0.5131, 0.1690, 0.6941},
		{1.1258, 0.3322, 0.0330, 0.0393, 1.1943, 0.0139, 0.0057, 0.0148, 1.1062, 0.0311, 0.0038, 1.7581, 0.0330, 0.0196, 1.0401, 0.0120, 0, 0.7529, 0.2877, 0.0637, 0.6874, 0.0153, 0.0124, 0.0005, 0.0857, 0, 0.0871},
		{2.6795, 0.0014, 0.3126, 0.0057, 1.8467, 0, 0.0005, 2.1334, 1.3953, 0, 1.2148, 0.7285, 0.0024, 0.0072, 3.0706, 0.0024, 0.0306, 1.0483, 0.2063, 1.3398, 0.9468, 0, 0.0010, 0, 0.2403, 0.0124, 0.8841},
		{0.7994, 0.0751, 0.0431, 0.3226, 3.3080, 0.0460, 0.2001, 0.0560, 2.4651, 0.0565, 0.0043, 0.4787, 0.1048, 0.1211, 0.8391, 0.0397, 0.0043, 0.5543, 0.7127, 0.0220, 0.4968, 0.0637, 0.0828, 0.0005, 0.1632, 0.0024, 5.3562},
		{2.1956, 0.3623, 1.7141, 5.6807, 1.2259, 0.6093, 0.5835, 0.1862, 0.4849, 0.0579, 0.0909, 2.3545, 1.3900, 4.9144, 0.3935, 0.9181, 0.1426, 10.0567, 9.0768, 2.0137, 0.2724, 0.5658, 0.4030, 0.7434, 0.3059, 0.0670, 5.1523},
		{0.5619, 0.0101, 0.0038, 0.0057, 0.7515, 0.5648, 0.0029, 0.0096, 1.1450, 0.0010, 0.0005, 0.6711, 0.0024, 0.0038, 0.7515, 0.0043, 0, 0.4519, 0.0962, 0.2168, 0.6041, 0, 0.0029, 0, 0.1426, 0, 0.1201},
		{0.9071, 0.0268, 0.0029, 0.0105, 1.6772, 0.0177, 0.4049, 0.5059, 1.0358, 0.0019, 0.0024, 0.7075, 0.0852, 0.3485, 0.5141, 0.0086, 0, 1.0047, 0.5170, 0.0292, 0.4825, 0, 0.0268, 0, 0.1886, 0.0019, 4.3807},
		{1.5547, 0.0440, 0.0101, 0.0163, 2.4230, 0.0321, 0.0029, 0.0163, 1.5623, 0.0034, 0.0053, 0.1340, 0.1197, 0.0847, 1.5413, 0.0172, 0.0010, 0.3183, 0.2020, 0.3681, 0.3863, 0.0005, 0.0527, 0, 0.4198, 0, 0.6194},
		{1.5896, 0.5916, 3.2989, 1.2077, 3.0510, 0.7812, 1.0373, 0.0230, 0.0201, 0.0110, 0.1441, 2.1468, 1.1990, 9.8183, 2.8169, 0.7462, 0.0766, 1.0315, 3.8987, 2.9203, 0.1604, 1.1574, 0.0124, 0.1125, 0.0043, 1.1856, 0.1828},
		{0.1809, 0, 0.0005, 0, 0.1537, 0, 0, 0, 0.0670, 0.0019, 0.0005, 0, 0, 0.0014, 0.1867, 0, 0, 0, 0, 0, 0.2465, 0, 0, 0, 0, 0, 0.0024},
		{0.2164, 0.0431, 0.0057, 0.0134, 1.1359, 0.0225, 0.0038, 0.0378, 0.7544, 0.0043, 0.0129, 0.1939, 0.0330, 0.1379, 0.0828, 0.0201, 0, 0.0474, 0.4610, 0.0258, 0.0450, 0.0038, 0.0402, 0, 0.1115, 0, 0.4471},
		{2.8442, 0.0737, 0.1388, 0.3571, 4.7387, 0.1245, 0.0842, 0.0302, 4.0409, 0.0010, 0.1565, 2.4282, 0.1446, 0.1077, 2.0817, 0.1216, 0.0029, 0.0268, 0.7625, 0.4815, 0.8568, 0.1393, 0.0325, 0.0010, 2.6877, 0.0034, 1.6040},
		{2.0994, 0.6184, 0.0120, 0.0062, 2.3512, 0.0354, 0.0014, 0.0077, 2.0975, 0.0014, 0.0043, 0.0512, 0.5174, 0.1067, 1.3015, 1.0952, 0.0019, 0.0158, 0.5126, 0.0096, 0.5074, 0.0077, 0.0105, 0, 0.1321, 0, 0.7831},
		{1.9678, 0.1067, 1.7438, 1.9989, 3.6546, 0.4174, 5.7511, 0.1455, 2.2775, 0.0675, 0.4021, 0.1910, 0.1235, 0.5237, 1.4006, 0.1484, 0.0646, 0.1469, 2.7997, 3.6144, 0.4112, 0.2609, 0.0905, 0.0144, 0.1623, 0.0416, 2.5383},
		{0.5170, 0.5265, 0.9286, 0.7362, 0.2882, 0.2848, 1.0693, 0.0670, 0.5897, 0.0177, 0.2738, 1.9175, 1.6193, 5.3974, 1.1751, 1.1249, 0.0321, 3.6517, 1.4542, 1.3326, 2.1530, 0.7271, 0.8209, 0.1915, 0.1685, 0.0747, 0.3308},
		{1.3728, 0.0235, 0.0211, 0.0120, 2.1334, 0.0191, 0.0062, 0.9310, 1.2857, 0.0048, 0.0129, 0.9434, 0.0306, 0.0306, 1.3666, 0.6692, 0, 1.7203, 0.5395, 0.4849, 0.5332, 0, 0.0220, 0, 0.1307, 0.0005, 0.3489},
		{0.0014, 0, 0, 0, 0.0005, 0, 0, 0, 0.0034, 0, 0, 0, 0, 0, 0.0010, 0, 0, 0.0005, 0.0005, 0.0010, 0.8089, 0, 0, 0, 0, 0, 0.0024},
		{4.1801, 0.3781, 0.5849, 0.7860, 6.0761, 0.1910, 0.4097, 0.1216, 4.1682, 0.0211, 0.3422, 0.3499, 0.7209, 0.5672, 2.9553, 0.3269, 0.0182, 0.7319, 3.3008, 1.1665, 0.8850, 0.2274, 0.0967, 0.0024, 0.7429, 0.0110, 3.6732},
		{1.0554, 0.0699, 1.1952, 0.0393, 2.7796, 0.0795, 0.0335, 1.7710, 2.1281, 0.0091, 0.2915, 0.6347, 0.7213, 0.3868, 0.9913, 1.0306, 0.1259, 0.0359, 2.7389, 4.9417, 1.1397, 0.0072, 0.2470, 0, 0.2896, 0.0010, 17.1461},
		{2.4785, 0.0852, 0.2891, 0.0244, 5.7564, 0.1029, 0.0412, 1.5432, 6.4600, 0.0038, 0.0024, 0.5591, 0.1149, 0.0914, 2.2143, 0.0426, 0, 2.3000, 1.8160, 0.9406, 0.9588, 0.0043, 0.1680, 0.0005, 0.7984, 0.0617, 2.8897},
		{0.5892, 0.5706, 0.6237, 0.4542, 0.5519, 0.1843, 0.3724, 0.0038, 0.5548, 0.0101, 0.0483, 1.5446, 1.0215, 2.4675, 0.1249, 0.5658, 0.0024, 1.8409, 1.9352, 1.2752, 0.0081, 0.0431, 0.0029, 0.0440, 0.0105, 0.0536, 0.0469},
		{0.6807, 0, 0.0005, 0.0010, 2.4957, 0, 0.0005, 0, 0.9760, 0, 0, 0.0014, 0, 0.0029, 0.3757, 0, 0, 0.0115, 0.0043, 0.0014, 0.0603, 0.0105, 0, 0, 0.0191, 0.0010, 0.0115},
		{0.7884, 0.0431, 0.0120, 0.0527, 0.6347, 0.0235, 0.0057, 0.2637, 0.6093, 0.0005, 0.0302, 0.1192, 0.0168, 0.1967, 0.4873, 0.0196, 0, 0.1398, 0.1843, 0.0182, 0.0096, 0, 0.0062, 0, 0.0201, 0.0038, 0.1527},
		{0.0862, 0.0024, 0.0957, 0, 0.2053, 0.0048, 0.0014, 0.0330, 0.2250, 0, 0, 0.0081, 0.0029, 0.0014, 0.0589, 0.1833, 0.0014, 0, 0.0067, 0.1584, 0.0507, 0.0024, 0.0053, 0.0043, 0.0364, 0, 0.1268},
		{0.1886, 0.0613, 0.1608, 0.0881, 0.2762, 0.0254, 0.0527, 0.0211, 0.2580, 0.0034, 0.0043, 0.1761, 0.1977, 0.1474, 0.1369, 0.2269, 0, 0.1259, 0.3982, 0.0890, 0.0153, 0.0062, 0.0503, 0.0134, 0, 0.0263, 4.8350},
		{0.2652, 0.0010, 0.0010, 0.0005, 0.9391, 0, 0.0010, 0.0024, 0.3633, 0.0005, 0.0019, 0.0598, 0.0038, 0.0005, 0.1139, 0.0048, 0.0014, 0, 0.0005, 0.0019, 0.0153, 0.0029, 0.0019, 0, 0.0349, 0.1192, 0.0263},
		{3.1304, 3.0055, 4.9407, 3.2032, 2.1511, 2.2502, 1.7198, 1.8764, 2.0965, 0.5007, 0.4614, 1.6097, 2.7781, 1.1842, 1.4183, 4.0437, 0.2762, 3.2568, 5.7947, 2.6470, 1.5853, 0.8736, 1.2981, 0.0378, 0.1761, 0.1268, 0}
	};

	return literal;
}

std::vector<std::vector<float>> generatePlaintextDictionaryDigramFrequencyMatrix() {
	std::vector<std::vector<float>> literal = {
		{0, 2.5938, 0.9976, 1.5962, 0, 0.1995, 1.1971, 0.1995, 1.1971, 0, 0.1995, 4.7885, 0.9976, 5.5866, 0, 0.9976, 0, 2.7933, 2.7933, 4.9880, 0.1995, 0.3990, 0.1995, 0, 0, 0.3990, 0.1995},
		{1.3966, 0.3990, 0, 0, 0, 0, 0, 0, 1.9952, 0.1995, 0, 1.1971, 0, 0.1995, 0.7981, 0, 0, 0.3990, 0.1995, 0, 0.3990, 0, 0, 0, 0.3990, 0, 0},
		{3.9904, 0, 0, 0, 1.1971, 0, 0, 1.5962, 1.7957, 0, 0.5986, 1.1971, 0, 0, 3.5914, 0, 0, 1.5962, 0.1995, 0.5986, 1.5962, 0, 0, 0, 0.1995, 0, 0.7981},
		{0.9976, 0, 0, 0, 4.7885, 0, 0.5986, 0.1995, 1.5962, 0, 0, 0.5986, 0, 0, 1.3966, 0, 0, 0.9976, 1.1971, 0, 0.9976, 0, 0, 0, 0.5986, 0, 4.9880},
		{1.3966, 0.1995, 1.7957, 4.5890, 0.5986, 1.3966, 0.5986, 0, 0.5986, 0.3990, 0, 2.1947, 1.3966, 4.1899, 0.1995, 0.5986, 0, 9.5770, 9.5770, 2.7933, 0.3990, 0.5986, 0.3990, 0.9976, 0.1995, 0.1995, 6.7837},
		{0.1995, 0, 0, 0, 0.3990, 0.3990, 0, 0, 1.5962, 0, 0, 0.5986, 0, 0, 1.3966, 0, 0, 0, 0, 0.3990, 0.9976, 0, 0, 0, 0.1995, 0, 0.1995},
		{1.7957, 0, 0.1995, 0, 2.1947, 0, 0.5986, 0.3990, 0.9976, 0, 0, 0.3990, 0.1995, 0.3990, 0.9976, 0, 0, 0.7981, 0.1995, 0, 0.5986, 0, 0, 0, 0.7981, 0, 4.1899},
		{0.7981, 0.1995, 0, 0, 1.7957, 0.1995, 0, 0, 1.7957, 0, 0, 0.3990, 0.5986, 0, 1.3966, 0, 0, 0.5986, 0, 0.3990, 1.1971, 0, 0, 0, 0.7981, 0, 0.5986},
		{0.7981, 0.5986, 2.5938, 1.7957, 2.1947, 0.7981, 1.5962, 0, 0, 0, 0, 2.3943, 1.7957, 7.1828, 3.3919, 1.1971, 0, 1.1971, 4.5890, 2.7933, 0.1995, 0.5986, 0, 0, 0, 1.9952, 0.3990},
		{0.5986, 0, 0, 0, 0.3990, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0.1995, 0, 0, 0, 0, 0, 0.5986, 0, 0, 0, 0, 0, 0},
		{0.3990, 0, 0, 0, 0.3990, 0, 0, 0, 0.1995, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0.1995, 0, 0.1995, 0, 0, 0, 0.1995, 0, 0.3990},
		{1.9952, 0, 0.3990, 0.7981, 3.9904, 0, 0, 0, 4.9880, 0, 0, 3.1923, 0.3990, 0.1995, 3.3919, 0.1995, 0, 0, 0.7981, 0.9976, 0.3990, 0.1995, 0, 0, 2.3943, 0, 2.1947},
		{2.5938, 0.5986, 0, 0, 3.3919, 0, 0, 0, 2.7933, 0, 0, 0.1995, 0, 0.1995, 1.3966, 0.5986, 0, 0, 0.7981, 0, 0.7981, 0, 0, 0, 0, 0, 1.3966},
		{1.7957, 0, 0.7981, 2.7933, 3.5914, 0.1995, 4.5890, 0, 2.1947, 0, 0.3990, 0, 0, 0.7981, 0.9976, 0, 0, 0, 3.3919, 3.1923, 0.9976, 0.3990, 0.1995, 0, 0.1995, 0, 2.1947},
		{0.3990, 0.1995, 0.7981, 1.1971, 0.5986, 0, 1.3966, 0.1995, 0.3990, 0, 0, 2.1947, 0.9976, 7.3823, 1.3966, 1.3966, 0, 4.9880, 0.9976, 1.3966, 1.3966, 1.1971, 0.7981, 0.3990, 0, 0, 0.7981},
		{1.3966, 0, 0, 0, 3.1923, 0, 0, 0.5986, 0.5986, 0, 0, 0.3990, 0, 0, 1.1971, 0.9976, 0, 2.1947, 0.5986, 0.7981, 0.3990, 0, 0, 0, 0, 0.1995, 0.5986},
		{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0.3990, 0, 0, 0, 0, 0, 0},
		{2.1947, 0, 0.9976, 0.7981, 8.7789, 0, 0.5986, 0.1995, 3.9904, 0, 0.1995, 0.3990, 0.7981, 0.1995, 3.3919, 0, 0, 0.3990, 4.9880, 0.9976, 0.5986, 0, 0, 0, 0.9976, 0, 2.3943},
		{1.5962, 0, 1.7957, 0.1995, 2.5938, 0, 0, 1.7957, 1.3966, 0.1995, 0.1995, 0.3990, 1.3966, 0.1995, 0.7981, 0.5986, 0, 0, 2.5938, 4.5890, 0.1995, 0, 0, 0, 0, 0, 18.1564},
		{2.5938, 0, 0, 0.1995, 4.7885, 0, 0, 1.9952, 5.9856, 0, 0, 0.1995, 0, 0, 1.7957, 0.1995, 0, 0.9976, 1.9952, 0.5986, 0.9976, 0, 0, 0, 0.5986, 0, 2.9928},
		{0.3990, 0.3990, 0.5986, 0.3990, 0.9976, 0.1995, 0.1995, 0, 0.1995, 0, 0, 2.7933, 1.3966, 1.1971, 0.1995, 0.3990, 0, 0.9976, 2.1947, 0.9976, 0, 0, 0, 0, 0, 0, 0},
		{0.1995, 0, 0, 0, 2.7933, 0, 0, 0, 0.1995, 0, 0, 0, 0, 0, 0.1995, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		{0.1995, 0.1995, 0, 0, 0.1995, 0, 0, 0, 0, 0, 0, 0.1995, 0, 0.1995, 0.3990, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0.1995},
		{0, 0, 0, 0, 0, 0, 0.1995, 0, 0, 0, 0, 0, 0, 0, 0, 0.5986, 0, 0, 0, 0.1995, 0, 0, 0, 0, 0.1995, 0, 0.1995},
		{0, 0, 0.3990, 0.1995, 0, 0, 0.3990, 0, 1.1971, 0, 0, 0.1995, 0.1995, 0, 0.1995, 0, 0, 0.1995, 0.1995, 0.1995, 0, 0, 0, 0, 0, 0, 4.3895},
		{0.5986, 0, 0.1995, 0, 1.3966, 0, 0, 0, 0.5986, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		{4.1899, 2.1947, 7.3823, 4.3895, 1.3966, 2.9928, 2.7933, 3.5914, 1.7957, 0.9976, 0.3990, 2.5938, 4.5890, 0.7981, 1.7957, 5.3871, 0.3990, 5.1875, 1.1971, 0, 0, 0, 0, 0, 0, 0, 0}
	};

	return literal;
}
