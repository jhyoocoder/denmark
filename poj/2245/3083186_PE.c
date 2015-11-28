/* 3:05 */

#include <stdio.h>
#define MAXN 50

int data[MAXN], chk[MAXN], k;

int boundf(int depth, int selected ) {
    return (depth + selected < 6 ) || ( selected > 6 ) ;
}

void combi(int depth, int index, int selected) {

    /* exit condition */

    int i;

    /*
        전체 깊이 depth : 골라야할 개수
        선택한 개수 selected
        현재 위치 index

        남아 있는 개수: depth
        골라야할 개수 6 - selected

    */

    if ( boundf(depth, selected) ) return; /* 남아있는 개수가 골라야할 개수보다 적으면 종료 */



    if ( depth == 0 ) {

        for (i =0; i < k ; i++)
            if ( chk[i] ) printf("%d ", data[i]);

        printf("\n");

    } else {

        /* selected */
        chk[index] = 1;
        combi(depth - 1, index + 1, selected + 1);

        /* not selected */
        chk[index] = 0;
        combi(depth - 1, index + 1, selected );

    }

}

int main()
{

    int i;

    while ( scanf("%d", &k) != EOF) {

        if (k == 0) break;

        for (i = 0; i < k; i++) {
            scanf("%d", &data[i]);
            chk[i] = 0;
        }

        combi(k, 0, 0); /* depth 6, start with index i */

    }

	return 0;
}
