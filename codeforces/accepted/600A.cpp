#include <iostream>
#include <cstring>

using namespace std;

const int nlen = 1e5;
char str[nlen+1];
// char words[nlen+1][nlen+1]; // too large
int words[nlen+1][2] = {-1,}; // st & en
int nw;
bool isnum[nlen+1];

int main() {
	cin >> str;
	int i,j, len = strlen(str);
	//parsing
	nw = 0; isnum[0] = true;
	
	for (i = 0; i <= len; i++) {
		if (str[i] == ',' || str[i] == ';' || str[i] == '\0') {
			words[nw][1] = i;
			if (words[nw][0] == -1) isnum[nw] = false;
			else if (i > words[nw][0]+1 && str[words[nw][0]] == '0') isnum[nw] = false;
			nw++;
			words[nw][0] = -1;
			isnum[nw] = true;
		} else {
			if (words[nw][0] == -1) words[nw][0] = i; // st
			isnum[nw] = isnum[nw] && (str[i] >= '0' && str[i] <= '9');
		}
	}
	// for debug
	// cout << nw << endl;
	int nnum = 0, nchar = 0;

	for (i = 0; i < nw; i++) {
		if (isnum[i]) nnum ++;
		else nchar++;
	}
	//cout << nnum << " , " << nchar << endl;
	if (nnum == 0) cout << "-" << endl;
	else {
		int k = 0;
		cout << "\"";
		for (i = 0; i < nw; i++) {
			
			if (isnum[i]) {
				k++;
				for (j = words[i][0]; j >= 0 && j < words[i][1]; j++) cout << str[j];
				if (k < nnum) cout << ",";
			}
		}
		cout << "\"" << endl;
	}
	if (nchar == 0) cout << "-" << endl;
	else {
		int k = 0;
		cout << "\"";
		for (i = 0; i < nw; i++) {
			if (!isnum[i]) {
				k++;
				for (j = words[i][0]; j >= 0 && j < words[i][1]; j++) cout << str[j];
				if (k < nchar) cout << ",";
			}
		}
		cout << "\"" << endl;

	}
	return 0;
}
