#include <iostream>
#include <cstring>

// I need to read English with keen eyes
// What i have read : m or n <= 16 : search space : 2^(16*16) ~ 2^(256) ~ (10^3)^26~ 10^(78)
// Truely saying : the product of m and n <= 16. Yes. area <= 16. Search space = 2^16 ~ 65536
using namespace std;

int m, n, answer; // row & col
bool board[16+2][16+2]; // for outside (toroidal structure)
bool newboard[16+2][16+2];

inline int count(int p, int q) {
	int pm1 = p-1, qm1 = q-1, pp1 = p+1, qp1=q+1;
	if (p == 1) pm1 = m;
	if (p == m) pp1 = 1;
	if (q == 1) qm1 = n;
	if (q == n) qp1 = 1;

	return newboard[pm1][qm1] + newboard[pm1][q]+ newboard[pm1][qp1]+ newboard[p][qm1]+newboard[p][qp1] + newboard[pp1][qm1] + newboard[pp1][q] + newboard[pp1][qp1];
}

bool chkboard() {
	for (int i = 1; i <= m; i++) {
		for (int j = 1; j <= n; j++) {
			int sum = count(i, j);
			
			if (newboard[i][j]) {
				if (sum == 2 || sum == 3) { 
					if (board[i][j] == false) return false; 
				} else if (board[i][j] == true) return false;
			} else {
				if (sum == 3) {
					if (board[i][j] == false) return false;
				}
				else if (board[i][j] == true) return false;
			}
		}
	}
/* multiple if-statement without braces can bother you....!!!!!
	cout << "-------"<< endl;
	for (int i = 1; i <= m; i++) {
		for (int j = 1; j <= n; j++) {
			int sum = count(i, j);
			if (newboard[i][j]) {
				cout << "O" << sum;
			} else {
				cout << "." << sum;
			}
		}
		cout << endl;
	}
	for (int i = 1; i <= m; i++) {
		for (int j = 1; j <= n; j++) {
			if (board[i][j]) {
				cout << "O";
			} else {
				cout << ".";
			}
		}
		cout << endl;
	}
*/
	return true;
}

void dfs(int ki, int kj) {
	if (ki == m && kj == n) {
		newboard[ki][kj] = true;
		if (chkboard()) answer++;
		newboard[ki][kj] = false;
		if (chkboard()) answer++;
	} else {
		newboard[ki][kj] = true;
		if (kj == n) dfs(ki + 1, 1);
		else dfs(ki, kj + 1);
		newboard[ki][kj] = false;
		if (kj == n) dfs(ki + 1, 1);
		else dfs(ki, kj + 1);
	}
}
void process() {
	answer = 0;
	dfs(1, 1);
}

int main() {
	int ncase = 1;
	cin >> m >> n;
	while (m != 0 && n != 0) {
		int k;
		cin >> k;
		memset(board, false, sizeof(board));
		memset(newboard, false, sizeof(newboard));
		for (int i = 0; i < k; i++) {
			int x, y;
			cin >> x >> y;	
			board[x+1][y+1] = true;
		}
		process();
		if (answer) 
			cout << "Case "<<ncase<<": "<<answer <<" possible ancestors." << endl;
		else
			cout << "Case "<<ncase<<": Garden of Eden." << endl;
		cin >> m >> n;
		ncase++;
	}
	return 0;
}