#include <stdio.h>

#define e1 1288
// = 28 * 23 * 2 = -5 * -10 * 2 = 100 = 1 (mod 33)
#define e2 14421
// = 23 * 33 * 19 = -5 * 5 * -9 = 25 * 9 = -3 * 9 = -27 = 1 (mod 28)
#define e3 5544
// = 28 * 33 * 6 = 5 * 10 * 6 = 300 = 70 = 24 = 1 (mod 23)
#define e4 21252
// = 23 * 28 * 33
int main() {
	int phyDay, emoDay, intDay, startDay,peakDay;
	int nCase = 0;
	// Chinese's Remainder Theorem

	while ( 1 ) {
		scanf("%d %d %d %d", &phyDay, &emoDay, &intDay, &startDay);
		if ( phyDay == -1 ) break;

		peakDay = phyDay * e3 + emoDay * e2 + intDay * e1 + e4 - startDay;

		if (peakDay > e4 ) peakDay %= e4;

		nCase ++;
		printf("Case %d: the next triple peak occurs in %d days.\n", nCase, peakDay);
	}
	return 0;
}