#include <iostream>
#include <string>
#include <vector>

using namespace std;

inline bool isLowercase(char c) {
	return (c >= 'a') && (c <= 'z');
}

inline char lowering(char c) {
	return c - 'A' +'a';
}

int ret;

void counting(string &acr, vector<string> &phr, int i, int j, int k) {
	if ( i < acr.length() && j < phr.size()) {
		if (acr.length() - i >= phr.size() - j) { 
			for (; k < phr[j].length(); k++) {
				if (lowering(acr[i]) == phr[j][k]) {
					counting(acr, phr, i+1, j, k+1);
					counting(acr, phr, i+1, j+1, 0);
				}
			}
		} 
	} else {
		if (i == acr.length() && j == phr.size() ) ret ++;
	}
}

void dynamic(string &acr, vector<string> &phr) {
	ret = 0;	
/*
	vector<string>::iterator iter;
	for (iter = phr.begin(); iter != phr.end(); iter++) {
		cout << *iter << " ";
	}
*/
	counting(acr, phr, 0, 0, 0);

	if (ret != 0) {
		cout << acr << " can be formed in " << 	ret << " ways" << endl;
	} else {
		cout << acr << " is not a valid abbreviation" << endl;
	}
}

int main() {
	int tcase;
	string acronym; 
	vector<string> phraseWords; // may be any length
	vector<string> ignWords;
	while (1) {
		cin >> tcase;
		if (tcase == 0) break;
		int t;
		string buf1, buf2;

		for (t = 0; t < tcase; t++) {
			cin >> buf1;
			ignWords.push_back(buf1);
		}

		cin >> buf1;
		while(1) {
			acronym = buf1;
			while (1) {
				cin >> buf2;
				if (isLowercase(buf2[0])) {
					vector<string>::iterator iter;
					bool flag = true;
					for (iter = ignWords.begin(); iter != ignWords.end(); iter++) {
						if (*iter == buf2) {
							flag = false;
							break;
						}
					}
					if (flag) phraseWords.push_back(buf2);
				} else break;
			}
			if (buf1 == "LAST" && buf2 == "CASE") break;
			buf1 = buf2; // next acronym
			
			dynamic(acronym, phraseWords);
			phraseWords.clear();
		}
		ignWords.clear();
	}
	
	return 0;
}