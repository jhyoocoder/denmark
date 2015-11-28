#include <stdio.h>
#define MAXN 50

int d[MAXN];

int main()
{
    int n, number, i, j;

    scanf("%d", &n);

    for ( i = 0; i < n; i++) {

        d[1] = 2;
        d[2] = 3;

        /* processing */
        scanf("%d", &number);

        for (j = 3; j <= number; j++) {
            d[j] = d[j - 2] + d[j - 1];
        }

        /* print */

        printf("Scenario #%d:\n%d\n\n", i + 1, d[number]);

    }

	return 0;
}
