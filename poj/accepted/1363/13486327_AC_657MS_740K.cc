#include <iostream>
#include <vector>

const int N = 1000;

using namespace std;

const char* msgStr[2] = {"No", "Yes"};

int Bside[N], n;

int isPossible() {
	int i, Aside[N];
	vector<int> station;
	for (i = 0; i < n; i++) Aside[i] = i+1;

	int ptrA = 0, ptrB = 0;
	station.push_back(-1);
	while (ptrA < n || ptrB < n) {
		if (station.back() == Bside[ptrB]) {
			station.pop_back();
			ptrB++;
		} else if (ptrA < n) {
			station.push_back(Aside[ptrA++]);
		} else break; // not possible
	}

	if (ptrA == n && ptrB == n) return 1;
	return 0;
}

int main() {
	int i;
	
	while (1) {
		cin >> n;
		if (n == 0) break;
		while (1) {
			int buf;
			cin >> buf;
			if (buf == 0) break;
			Bside[0] = buf;
			for (i = 1; i < n; i++)	cin >> Bside[i];
			cout << msgStr[ isPossible() ] << endl;
		}
		cout << endl;
	}
	return 0;
}