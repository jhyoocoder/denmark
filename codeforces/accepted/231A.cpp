#include <iostream>

using namespace std;

int main() {
	int p, v, t;
	int n,i,cnt =0 ;
	cin >> n;

	for (i =0 ; i < n; i++) {
		cin >> p >> v >> t;
		cnt += ((p & v) | (v & t) | (t & p));
	}
	cout << cnt << endl;
	return 0;
}
