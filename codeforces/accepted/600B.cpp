//600B Queries about less or equal elements
/* hacked by the following code Hack #186722
** Generator source **
#include <bits/stdc++.h>
using namespace std;

int main() {
	printf("200000 200000\n");
	for (int i=0;i<199999;i++) printf("13 ");
	printf("14\n");
	for (int i=0;i<200000;i++) printf("13%c",i==199999 ? '\n' : ' ');

	return 0;
}
*/
#include <iostream>
#include <algorithm>
using namespace std;

const int cmax = 2*(1e5);
int n, m;
int a[cmax], b[cmax];

int main() {
	cin >> n >> m;
	int i,j;
	// input
	for (i = 0; i < n; i++) cin >> a[i];
	for (i = 0; i < m; i++) cin >> b[i];

	sort(a, a+n);

	for (j = 0; j < m; j++) {
		int ref = b[j];
		if (b[j] < a[0]) cout << "0 ";
		else if (b[j] >= a[n-1]) cout << n << " ";
		else {
			int l = 0, r = n-1, m;
			while (l < r) {
				m = (l+r)/2;
				if (m == l || m == r) {
					m = l;
					while (a[m] <= ref) m++;
					cout << m << " ";
					break;
				}
				if (a[m] > ref) r = m;
				else if (a[m] < ref) l = m;
				else if (a[m] == ref) {
					while (a[m] == ref) m++;
					cout << m << " ";
					break;
				}
			}

		}
	}
	cout << endl;

	return 0;
}
