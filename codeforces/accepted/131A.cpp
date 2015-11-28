#include <iostream>
#include <cstring>

using namespace std;

int main() {
	char str[101], nstr[101];
	int i, len;
	bool f = false, s = true;

	cin >> str;
	len = strlen(str);
	for (i = 1;i < len; i++) {
		if (str[i] >= 'a') s = false;	
	}

	if (s) {
		for (i = 1;i < len; i++) {
			str[i] = str[i] - 'A' + 'a';	
		}
		if (str[0] <= 'Z') str[0] = str[0] - 'A' + 'a';	
		else  str[0] = str[0] + 'A' - 'a';	
	}

	cout << str << endl; // this one needs proper parenthesis
	return 0;
}
