#include <iostream>
#include <cstring>

using namespace std;

int main() {
	char str[101];
	int i, len, cnt = 0;
	cin >> len;
	cin >> str;

	for (i = 1;i < len; i++) {
		if (str[i] == str[i-1]) cnt++;	
	}

	cout << cnt << endl; 
	return 0;
}
