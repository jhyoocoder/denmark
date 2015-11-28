#include <iostream>

using namespace std;

int main() {
	int m, N;
	cin >> m >> N;
	if (m & 1) {
		cout << ((m >> 1)*N+(N>>1));
	} else {
		cout << ((m >>1) * N);
	}
	cout << endl;
	return 0;
}
