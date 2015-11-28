#include <iostream>
using namespace std;

const int MAXSIZE = 1000;

char board[MAXSIZE+4][MAXSIZE+4];  // +2 to allow for easy processing of knight moves
bool safe[MAXSIZE+4][MAXSIZE+4];
int numsafe;

void process(int i, int j)
{
	if (safe[i][j])
		numsafe--;
	safe[i][j] = false;
}

int main()
{
	int n, m, i, j, k;
	int nboard = 0;
	cin >> n >> m;
	while (n != 0) {
		nboard++;
		for(i=2; i<n+2; i++) {
			for(j=2; j<m+2; j++) {
				board[i][j] = ' ';
				safe[i][j] = true;
			}
		}
		for(i=0; i<n+4; i++) {
			board[i][0] = board[i][1] = board[i][m+2] = board[i][m+3] = '+';
			safe[i][0] = safe[i][1] = safe[i][m+2] = safe[i][m+3] = false;
		}
		for(j=0; j<m+4; j++) {
			board[0][j] = board[1][j] = board[n+2][j] = board[n+3][j] = '+';
			safe[0][j] = safe[1][j] = safe[n+2][j] = safe[n+3][j] = false;
		}
		numsafe = n*m;
		char chUnit[3] = {'q','k','p'};
		int num;
		for (k = 0; k < 3; k++) {
			cin >> num;
			for(i=0; i<num; i++) {
				int r, c;
				cin >> r >> c;
				board[r+1][c+1] = chUnit[k];
			}
		}
		for(i=2; i<n+2; i++) {
			for(j=2; j<m+2; j++) {
				switch (board[i][j]) {
				case 'p' :
					process(i, j);
					break;
				case 'k' :
					process(i, j);
					process(i+1, j+2);
					process(i+1, j-2);
					process(i-1, j+2);
					process(i-1, j-2);
					process(i+2, j+1);
					process(i+2, j-1);
					process(i-2, j+1);
					process(i-2, j-1);
					break;
				case 'q' :
					process(i, j);
					for(k=i-1; k>=2; k--) {
						if (board[k][j] != ' ')
							break;
						process(k, j);
					}
					for(k=i+1; k<n+2; k++) {
						if (board[k][j] != ' ')
							break;
						process(k, j);
					}
					for(k=j-1; k>=2; k--) {
						if (board[i][k] != ' ')
							break;
						process(i, k);
					}
					for(k=j+1; k<m+2; k++) {
						if (board[i][k] != ' ')
							break;
						process(i, k);
					}
					for(k=i-1; k>=2; k--) {
						if (board[k][j+k-i] != ' ')
							break;
						process(k, j+k-i);
					}
					for(k=i+1; k<n+2; k++) {
						if (board[k][j+k-i] != ' ')
							break;
						process(k, j+k-i);
					}
					for(k=i-1; k>=2; k--) {
						if (board[k][j+i-k] != ' ')
							break;
						process(k, j+i-k);
					}
					for(k=i+1; k<n+2; k++) {
						if (board[k][j+i-k] != ' ')
							break;
						process(k, j+i-k);
					}
					break;
				}
			}
		}
		cout << "Board " << nboard << " has " << numsafe << " safe squares." << endl;

		cin >> n >> m;
	}
    return 0;
}