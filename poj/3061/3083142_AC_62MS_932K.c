#include <stdio.h>
#include <stdlib.h>

#define MAXN 100000

int data[MAXN + 1];
int sum[MAXN + 2], S; /* sum[j] j번째 까지의 합 */

int cmp(const void *a, const void *b) {
    return *(int*)a - *(int*)b;
}

int search(int i, int l, int r) {
    int m, n = r;


    while ( l <= r ) {
        m = (l + r )/ 2;

        if ( sum[m] - sum[i - 1] > S)
            r = m - 1;
        else if ( sum[m] - sum[i - 1] < S )
            l = m + 1;
        else return m;
    }

    while ( m <= n && sum[m] - sum[i - 1] < S ) m++;

    if ( m <= n )    return m;

    return -1;
}

int main() {

    int n, i, key, index = -1, c, t, result, len;
    sum[0] = 0;

    scanf("%d", &c);

    for (t = 0; t < c; t++) {
        scanf("%d%d", &n, &S);


        for (i = 1; i <= n; i++) {
            scanf("%d", &data[i]);
            sum[i] = data[i] + sum[i - 1];
        }

        /* 순서쌍 (i, j) 생성. 각 i에 대하여 j는 BS로 찾음*/
        result = n;

        if ( sum[n] < S ) {
            printf("0\n");
            continue;
        }

        for (i = 1; i <= n; i++) {
            index = search(i, i, n);

            if ( index != -1 ) {
                len = index - i + 1;
                if ( result > len ) {
                    result = len;

                }
            }
        }

        printf("%d\n", result);
    }

    return 0;
}