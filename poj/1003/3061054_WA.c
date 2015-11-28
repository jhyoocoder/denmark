#include <stdio.h>
#include <stdlib.h>

#define MAXN 300

int main() {


    double c, cardlength[MAXN];

    int i, mid, left, right;

    cardlength[0] = 0.0;
    for (i = 1; i < MAXN; i++) {
        cardlength[i] = cardlength[i - 1] + ((double)1/(double)(i+1));
    }


    while (scanf("%lf", &c) != EOF) {

        if (c == 0.0 ) break;

        left = 0; right = MAXN - 1;

        do {

            mid = (left + right) / 2;


            if ( cardlength[mid] > c )

                right = mid;

            else if ( cardlength[mid] < c )

                left = mid;

            else if ( cardlength[mid] == c ) {
                right = mid;
                break;
            }

            printf("(%d, %d)\n", left, right);


        } while ( right - left != 1 );

        printf("%d card(s)\n", right );

    }



    return 0;

}