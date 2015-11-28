#include <iostream>

using namespace std;

int main() {
	int n, i,a, b, c = 0, mc = 0;
	cin >> n;
	
	for (i = 0;i < n; i++) {
		cin >> a >> b;
		c += (b - a);
		if (mc < c) mc = c;
	}
	cout << mc << endl;
	return 0;
}
