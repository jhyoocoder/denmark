//600F
#include <iostream>

using namespace std;

const int cmax = 1e5;

int nca[1001];
int ncb[1001];
int na[1001];
int nb[1001];
int gca[1001][10000];
int gcb[1001][10000];
int edge[1001][2];
int main() {
	int a, b, m;
	cin >> a >> b >> m;	
	int i, p, q, cm = -1;

	for (i = 0; i < m; i++) {
		cin >> p >> q;
		edge[i][0] = p;
		edge[i][1] = q;
		
		nca[p]++;
		ncb[q]++;
	}
	for (i = 0; i < a; i++)
		if (cm < nca[i]) cm = nca[i];
	for (i = 0; i < b; i++)
		if (cm < ncb[i]) cm = ncb[i];
	cout << cm << endl;
	int c;
	for (i = 0; i < m; i++) {
		for (c = 1; c <= cm; c++) {
			bool chk = true;
			for (p = 0; p < na[edge[i][0]]; p++) 
				if(gca[edge[i][0]][p] == c) {
					chk = false;
					break;
				}
			for (q = 0; q < nb[edge[i][1]]; q++) 
				if(gcb[edge[i][1]][q] == c) {
					chk = false;
					break;
				}
			if (chk) {
				cout << c << " ";
				gca[edge[i][0]][na[edge[i][0]]++] = c; 
				gcb[edge[i][1]][nb[edge[i][1]]++] = c;
				break;
			}		
		}
		// max color
		
	}
	cout << endl;
	return 0;
}
