/*
(1)Stack;

top : 삽입 된 곳

pop, push

(2) Loop의 종료 조건은 변수들의 의미를 잘 파악한뒤, 종료시의 이들 값들을 출력해본다. -> 가장 빠른 확인 방법.

*/
#include <stdio.h>

#define MAXN 1000


int stack[MAXN], top = -1;
int rails[MAXN], n;

int push( int *k ) {

    if ( top == MAXN - 1 ) return 0;

    stack[++top] = *k;

    return 1;
}

int pop ( int *k ) {

    if ( top == -1 ) return 0;

    *k = stack[top--];

    return 1;
}

void proc() {

    int index1, index2, chk = 1, key;

    index1 = 0; index2 = 1;

    while (1) {

        do {
            push ( &index2 );
            index2++;
            /*printf("Push %d\n", stack[top]);*/
            if ( stack[top] == rails[index1] || index2 > n ) break;
        } while (1);

        while ( top >= 0 && stack[top] == rails[index1] ) {
            pop( &key );
            /*printf("Pop %d\n", key);*/
            index1++;
        }

        if ( index2 > n ) {
            if ( index1 < n ) chk = 0;
            break;
        }

    }

    if ( chk ) printf("Yes\n");
    else printf("No\n");
}

int main()
{
    int i, buf;

    while ( scanf("%d", &n) != EOF ) {
        if ( n == 0 ) break;

        scanf("%d", &buf);

        while (buf != 0) {

            rails[0] = buf;

            for (i = 1; i < n; i++)
                scanf("%d", &rails[i]);

            proc();

            scanf("%d", &buf);
        }

        printf("\n");

    }
	return 0;
}