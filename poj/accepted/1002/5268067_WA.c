#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX 100000

int total;
int data[MAX];
int table[27] = {2,2,2,3,3,3,4,4,4,5,5,5,6,6,6,7,0,7,7,8,8,8,9,9,9,0};

int comp(const void *a, const void *b) {
	return (*(int*)a) - (*(int*)b);
}

int mapping(char *s) {
	int result, i;
	int len = strlen(s);

	result = 0;

	for (i = 0; i < len; i++) {
		if (s[i] == '-' ) continue;
		if ('0' <= s[i] && s[i] <= '9')
			result = result * 10 + s[i] - '0';
		else 
			result = result * 10 + table[s[i] - 'A'];
	}

	return result;
}


int main() {
	char buf[30];
	int cnt, i, nodup;
	scanf("%d", &total);

	for (i = 0; i < total; i++)	{
		scanf("%s", buf);
		data[i] = mapping(buf);
	}

	qsort((void*)data, total, sizeof(data[0]),comp);

	cnt = 1;
	nodup = 1;
	for (i = 0; i < total - 1; i++) {
		while ( i < total - 1 && data[i] == data[i + 1] ) {
			cnt++;
			i++;	
		}
		if ( cnt > 1 ) {
			printf("%03d-%04d %d\n", data[i] / 10000, data[i] % 10000, cnt);
			nodup = 0;
		}
		cnt = 1;
	}

	if (nodup)
		printf("No duplicates.");
	return 0;
}