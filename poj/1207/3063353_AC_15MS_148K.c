/* 5:59 */
/* 6:04 */

#include <stdio.h>


void swap ( int *a, int * b) {
    int t = *a;
    *a = *b;
    *b = t;
}

int main()
{

	int maxlength, start, end, i, val, len, chk;

	while ( scanf("%d %d", &start, &end) != EOF) {

        chk = 0;
	    if ( start > end ) {
	        swap ( &start, & end);
	        chk = 1;

	    }

	    maxlength = 0;

	    for (i = start; i <= end; i++) {

	        val = i;
	        len = 1;

	        while ( val != 1 ) {

	            if ( val & 1 ) val = 3 * val + 1;
	            else val >>= 1;

	            len ++;

	        }

	        if ( len > maxlength ) maxlength = len;
	    }

	    if ( chk )
            printf("%d %d %d\n", end, start, maxlength);
        else
            printf("%d %d %d\n", start, end, maxlength);

	}

	return 0;
}
