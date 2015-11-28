#include <stdio.h>
#include <string.h>

const char *tname[20] = {"imix", "ik", "akbal", "kan", "chicchan", "cimi", "manik", "lamat", "muluk", "ok", "chuen", "eb", "ben", "ix", "mem", "cib", "caban", "eznab", "canac", "ahau"};

const char *hname[19] = {"pop", "no", "zip", "zotz", "tzec", "xul", "yoxkin", "mol", "chen", "yax", "zac", "ceh", "mac", "kankin", "muan", "pax", "koyab", "cumhu", "uayet"};

int lookUpName ( const char *name) {
	int index;

	for (index = 0 ; index < 19; index ++) {
		if (strcmp (hname[index] , name ) == 0) break;
	}
	return index;
}
int main() {
	int n, i;
	int hDay, hYear, hMon; char hMonName[10];
	int tDay, tYear, tNum;
	int Day;

	scanf("%d", &n);
	printf("%d\n", n);

	for (i = 0; i < n; i++) {
		scanf("%d. %s %d", &hDay, hMonName, &hYear);
		hMon = lookUpName(hMonName);
//		printf("%d, %s ", hMon, hMonName);
		Day = hYear * 365 + hMon * 20 + hDay;
		tYear = Day / 260;
		tDay = (Day % 260) % 20;
//		printf("%d\n", Day % 260);
		tNum = ((Day % 260) % 13) + 1;
		printf("%d %s %d\n", tNum, tname[tDay], tYear);
	} 
	return 0;
}