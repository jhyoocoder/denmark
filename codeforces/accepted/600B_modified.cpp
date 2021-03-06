//600B Queries about less or equal elements

#include <iostream>
#include <algorithm>
using namespace std;

const int cmax = 2*(1e5);
int n, m;
int a[cmax], b[cmax], c[cmax];

int main() {
	cin >> n >> m;
	int i,j;
	// input
	for (i = 0; i < n; i++) cin >> a[i];
	for (i = 0; i < m; i++) cin >> b[i];

	sort(a, a+n);
	c[n-1] = n;
	for (i = n-1; i > 0; i--) if (a[i] == a[i-1]) c[i-1] = c[i]; else c[i-1] = i;
	c[0] = 1;

	for (j = 0; j < m; j++) {
		int ref = b[j];
		if (ref < a[0]) cout << "0 ";
		else if (ref >= a[n-1]) cout << n << " ";
		else {
			int l = 0, r = n-1, m;
			while (l < r) {
				m = (l+r)/2;
				if (m == l || m == r) {
					m = l;
					while (a[m] <= ref) m = c[m];
					cout << m << " ";
					break;
				}
				if (a[m] > ref) r = m;
				else if (a[m] < ref) l = m;
				else if (a[m] == ref) {
					cout << c[m] << " ";
					break;
				}
			}

		}
	}
	cout << endl;

	return 0;
}
