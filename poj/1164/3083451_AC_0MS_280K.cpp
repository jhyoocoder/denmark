/*
	ID : jaehun83
	PROG : castle
*/

#include <iostream>

using namespace std;

typedef struct point {
	int x,y;
} Point;

typedef struct block {
	int chk[4],bnum;
} Block;

void inp();
void outp();
void search(int,int);

const int dx[4] = {-1,0,1,0};
const int dy[4] = {0,-1,0,1};

int m,n,cnt,blarea[2501],marea,msarea; // 배열 크기 상의 문제점
char cd;
Point c;
Block a[50][50];

int main() {

	inp();
	marea = -1;

	for (int i=0;i<m;i++) {
		for (int j=0;j<n;j++) {

			if (a[i][j].bnum==0) { //cnt 변수와 ~.bnum의 0값의 충돌로 인한 오류
				cnt++;
				search(i,j);
				if (blarea[cnt] > marea) marea = blarea[cnt];
			}
		}
	} // count block and calculate the block's area

	outp();
	return 0;
}

void search(int y, int x) {

	int tx,ty;
	a[y][x].bnum = cnt;
	blarea[cnt]++;
	for (int k=0;k<4;k++) {
		if (a[y][x].chk[k]==1) {
			tx=x+dx[k]; ty=y+dy[k];
			if (((0<=tx && tx < n) && (0<=ty && ty < m)) && a[ty][tx].bnum==0) search(ty,tx);
		}
	}
}

void inp() {

	cin >> m >> n;
	int buff;
	for (int i=0;i<m;i++) {
		for (int j=0;j<n;j++) {
			cin >> buff;
			for (int k=0;k<4;k++) {
				a[i][j].chk[k] = 1 - (buff % 2); // 토글
				buff /= 2;
			}
		}
	}
	cnt = 0;
}

void outp() {
	cout << cnt << endl;
	cout << marea << endl;

}