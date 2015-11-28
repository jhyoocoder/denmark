/* 12:12 */
/* coding starts at 21 */


#include <stdio.h>
#include <string.h>

#define MAXN 100
#define MAXLEN 12

typedef struct _node {
    int r,l,b; /*right, left, check bit*/
} node;

node tree[MAXN];
int chk, itree;

char *word[2] = {"", "not "};

void init() {
    int i;

    itree = 0;

    for (i = 0; i < MAXN; i++) {

        tree[i].l = tree[i].r = tree[i].b = 0;

    }

}

void insert_tree( char *code) {
    int i, len, pt;

    len = strlen(code);

    pt = 0; /* root of tree */

    for (i = 0; i < len; i++) {

        if ( tree[pt].b != 0 ) {
            chk = 1;
            break;
        }

        if ( code[i] == '0' ) {/* to the left node*/

            if (tree[pt].l == 0) { /* is empty? */

                itree++;

                tree[pt].l = itree;

            }

            pt = tree[pt].l;

        } else {

            if ( tree[pt].r == 0) {
                itree++;
                tree[pt].r = itree;
            }

            pt = tree[pt].r;

        }

    }

    if ( !chk )
        tree[pt].b = 1;
}

int main() {

    char buff [MAXLEN];

    int ncase = 1; chk = 0;

    while (scanf("%s", buff) != EOF) {

        if (buff[0] == '9') {
            printf("Set %d is %simmediately decodable\n", ncase, word[chk]);

            init();

            ncase++;
            chk = 0;
        }
        if ( !chk ) insert_tree( buff);

    }


    return 0;
}