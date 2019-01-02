#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <random>
#include <chrono>

using namespace std;

bool compareVectors(vector<string> left, vector<string> right, int len) {
	for (int i = 0; i < len; i++) {
		if (left[i] == right[i])
			return false;
	}
	return true;
}

int main() {

	vector<string> dementi = {"Aneta", "Anna", "Michal", "Nela"};

	unsigned seed = chrono::system_clock::now().time_since_epoch().count();
	default_random_engine rng(seed);
	vector<string> dementiMix = dementi;

	while (!compareVectors(dementi, dementiMix, 4))
		shuffle(dementiMix.begin(), dementiMix.end(), rng);

	for (int i = 0; i < 4; i++) {
		cout << dementi[i] << " --> " << dementiMix[i] << endl;
	}

	return 0;
}