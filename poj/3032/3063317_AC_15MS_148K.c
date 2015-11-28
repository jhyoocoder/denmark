#include <stdio.h>

#define MAXN 13

typedef struct _node {
    int data, link;
} node;

node list[MAXN + 1];

int n;


void init() {

    int i;

    for (i = 0; i < n; i++) {

        list[i].data = list[i].link = i + 1;

    }

    list[n - 1].link = 0;

}

int main()
{

    int testcase;
    int i , t, point, prev, j;

    scanf("%d", &testcase);

    for (t = 0; t < testcase; t++) {

        scanf("%d", &n);

        init(); /* initiate linked list */

        /* proc 1..n */

        point = 0; prev = n - 1;

        for (i = 1; i <= n; i++) { /* fill from 1 to n */

            for (j = 0; j < i; j++) {
               prev = point;
               point = list[point].link;
            }

            list[point].data = i;

            list[prev].link = list[point].link;

            point = list[point].link;

        }

        for (i = 0; i < n; i++)
            printf("%d ", list[i].data);

        printf("\n");

    }



	return 0;
}
