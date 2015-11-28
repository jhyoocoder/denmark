#include <stdio.h>
#include <stdlib.h>

#define MAX 30000
#define PMAX 924
#define EMAX 759
#define IMAX 644

int days[MAX];
int p, e, i, d;
int answer;

void init() {
	int k;

	for(k = 0; k < MAX; k++) days[k] = 0;

	days[p]++;
	days[e]++;
	days[i]++;
}

void proc() {
	int k, mday;

	mday = p;
	for (k = 1; k <= PMAX; k++) {
		mday += 23;
		days[mday]++;
	}

	mday = e;
	for (k = 1; k <= EMAX; k++) {
		mday += 28;
		days[mday]++;
	}

	mday = i;
	for (k = 1; k <= IMAX; i++) {
		mday += 33;
		days[mday]++;
		if (days[mday] == 3) {
			answer = mday - d;
			break;
		}
	}
	
}

int main() {
	int cnt = 1;

	while(1) {
		scanf("%d %d %d %d", &p, &e, &i, &d);
		if (p == -1) break;
		init();
		proc();
		printf("Case %d: the next triple peak occurs in %d days.\n", cnt++, answer);
	}

	return 0;

}
