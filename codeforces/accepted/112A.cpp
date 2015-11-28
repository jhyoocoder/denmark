#include <iostream>
#include <cstring>

using namespace std;

int main() {
	char str[101], nstr[101];
	int i, len, order = 0;

	cin >> str >> nstr;
	len = strlen(str);

	for (i = 0;i < len; i++) {
		if (str[i] <= 'Z') str[i] = str[i] - 'A' + 'a';
		if (nstr[i] <= 'Z') nstr[i] = nstr[i] - 'A' + 'a'; 
	}

	for (i = 0; i < len && (str[i] == nstr[i]); i++);

	if (str[i] < nstr[i]) order = -1;
	else if (str[i] > nstr[i]) order = 1;

	cout << order << endl;
	return 0;
}
