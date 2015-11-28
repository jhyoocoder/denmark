/* 11:24 */

#include <string.h>
#include <stdio.h>
#include <stdlib.h>

#define MAXLEN 20
#define MAXN 100000

char phones[MAXN][MAXLEN];
char check[MAXN];

int compare(const void *a, const void *b) {
    char *str1 = (char*)a;
    char *str2 = (char*)b;

    return strcmp(str1, str2);
}

int main()
{

    int ncase, i, j, k, val, cnt;
    char buff[MAXLEN], isduplicate;

    scanf("%d", &ncase);

    for (i = 0; i < ncase; i++) {
        scanf("%s", phones[i]);
        check[i] = 0;
    }

    for (i = 0; i < ncase; i++) { /* convert to standard form */
        k = 0;
        for (j = 0; j < strlen(phones[i]); j++) {
            if ( ('A' <= phones[i][j] && phones[i][j] <= 'Z') ) {

                switch ( phones[i][j] ) {
                    case 'A': case 'B': case 'C':
                        val = 2;
                        break;
                    case 'D': case 'E': case 'F':
                        val = 3;
                        break;
                    case'G': case 'H': case 'I':
                        val = 4;
                        break;
                    case'J': case 'K': case 'L':
                        val = 5;
                        break;
                    case'M': case 'N': case 'O':
                        val = 6;
                        break;
                    case'P': case 'R': case 'S':
                        val = 7;
                        break;
                    case'T': case 'U': case 'V':
                        val = 8;
                        break;
                    case'W': case 'X': case 'Y':
                        val = 9;
                        break;
                }

                buff[k++] = val + '0';

            } else if ('0' <= phones[i][j] && phones[i][j] <= '9') {
                    buff[k++] = phones[i][j];
            }

        }

        buff[k] = '\0';
        strcpy(phones[i], buff);

    }

    qsort(phones, ncase, sizeof(phones[0]), compare);


    isduplicate = 0;
    for (i = 0; i < ncase - 1; i++) {

        if ( check[i] == 0 ) {
            cnt = 1;

            for (j = i+1; j < ncase; j++) {

                if ( !strcmp(phones[i], phones[j]) ) {

                    cnt ++;
                    check[j] = 1;

                }

                else break;

            }

            if ( cnt > 1 ) {

                for (j = 0; j < 3; j++) printf("%c", phones[i][j] );
                printf("-");
                for (j = 3; j < 7; j++) printf("%c", phones[i][j] );

                printf(" %d\n", cnt);
                isduplicate = 1;
            }

        }

    }

    if (!isduplicate) printf("No duplicates\n");


	return 0;
}
