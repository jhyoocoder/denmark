#include <iostream>

using namespace std;

int main() {
	int n, i, x = 0;
	char str[4];
	cin >> n;

	for (i =0 ; i < n; i++) {
		cin >> str;
		if (str[1] == '+') ++x;
		else --x;
	}
	cout << x << endl;
	return 0;
}
