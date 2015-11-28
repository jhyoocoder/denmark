#include <stdio.h>

#define MAXN 100

int triangle [MAXN + 2][MAXN + 2];

int max( int a, int b) {

    if ( a>= b)
        return a;
    else
        return b;
}

int main() {

    int n, i, j, result;

    scanf("%d", &n);

    for (i = 1; i <= n; i++) {
        for (j = 1; j <= i; j++) {
            scanf("%d", &triangle[i][j]);
        }
    }

    for (i = 2; i <= n; i++) {
        for (j = 1; j <= i; j++) {

            triangle[i][j] += max ( triangle[i - 1][j - 1], triangle[i - 1][j] );

        }
    }

    result = 0;

    for (i =1; i <= n; i++)
        if ( result < triangle[n][i] ) result = triangle[n][i];

    printf("%d\n", result);

    return 0;
}