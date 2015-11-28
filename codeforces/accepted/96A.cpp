#include <iostream>
#include <cstring>

using namespace std;

int main() {
	char str[101];
	bool danger = false;
	int cnt = 0, len, i;

	cin >> str;
	len = strlen(str);
	for (i = 0;i < len - 1; i++) {
		if (str[i] == str[i+1]) cnt++;
		else cnt = 0;
		if (cnt >= 6) {
			danger = true; break;
		}
	}
	cout << ((danger) ? "YES" : "NO") << endl; // this one needs proper parenthesis
	return 0;
}
