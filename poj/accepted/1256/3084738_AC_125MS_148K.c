#include <stdio.h>
#include <string.h>

#define MAXN ('Z' - 'A' + 1)

int alphabet[MAXN*2], cnt, len; /* 0 : lower, 1 : upper */
int available[15];
int result[15];

int num ( char a ) {
    int rank, k , c;

    if ( 'a' <= a && a <= 'z' ) rank = a - 'a' + 'Z' - 'A' + 1;
    if ( 'A' <= a && a <= 'Z' ) rank = a - 'A';

    k = rank % MAXN;
    c = rank / MAXN;

    return c + 2 * k;
}

char ctoi ( int b ) {
    int a, c;

    a = b / 2;
    c = b % 2;

    if (c ) return a + 'a';
    else return a + 'A';
}

void proc(char *str) {
    int i;

    len = strlen(str);

    cnt = 0;

    for (i = 0; i < MAXN * 2; i++)
        alphabet[i] = alphabet[i] = 0;

    for (i = 0; i < len; i++)
        alphabet[num(str[i])]++;

    for (i = 0; i < MAXN * 2; i++)
        if ( alphabet[i] ) available[cnt++] = i;
}

void searching(int depth) { /* depth : 1 ~ len */
    int i;

    if ( depth >= len ) {

        for (i = 0; i < len; i++) { /* output */
            printf ("%c", ctoi(result[i]) );
        }

        printf("\n");

    } else {

        for (i = 0; i < cnt; i++) {
            if ( alphabet[available[i]] > 0 ) {
                result[depth] = available[i];
                alphabet[available[i]] --;
                searching(depth + 1);
                alphabet[available[i]] ++;
            }
        }

    }
}



int main()
{

    int n, i;
    char r;
    char buff[15];

    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        scanf("%s", buff);

        proc(buff);

        searching(0);
    }


	return 0;
}
