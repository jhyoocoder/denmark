#include <stdio.h>
#include <string.h>

#define MAXLEN 300

typedef struct _longdouble {

    int point, h[MAXLEN], size;
} longdouble;


void assign( longdouble *a, const char *s) {
    int i, len = strlen(s), j = 0;

    for (i = len - 1; i >= 0; i--) {

        if ( s[i] == '.' ) {
            a->point = i;
            continue;
        }

        a->h[j++] = s[i] - '0';

    }

    a->point = j - a->point;
    a->size = j;
}

void print ( longdouble *a) {

    int i, chk;

    if ( a-> h[a->size - 1] == 0 ) {

        chk = a->point - 1;

        for (i = a->size - 1; i >= a->point;i--)
            if ( a->h[i] != 0 ) {
                chk = i;
                break;
            }

        for (i = chk; i >= 0; i--) {
            if ( a->point - 1 == i ) printf(".");
            printf("%d", a->h[i]);
        }


    } else {

        for (i = a->size - 1; i >= 0; i--) {
            if ( a->point - 1 == i ) printf(".");
            printf("%d", a->h[i]);
        }
    }

    printf("\n");
}

void init(longdouble *a) {
    for (int i = 0; i < MAXLEN; i++)
        a->h[i] = 0;

    a->point = 0;
    a->size = 1;
}

void trim (char *s) {

    int len = strlen(s), i, chk = 0;

    for (i = 0; i < len; i++)
        if ( s[i] == '.') {
            chk = 1;
            break;
        }

    if ( chk ) {
        i = len - 1;
        while ( s[i] == '0' ) { i--; }
        if ( i != len - 1 ) s[i + 1] = '\0';
    }

}

int main() {

    char base[10];
    int n , i, j, k, l, carrier, t;
    longdouble result, a, b, buff1, buff2;


    while (scanf("%s %d", base, &n) != EOF) {

        trim(base);
        assign(&b, base);
        assign(&a, base);


        for (i = 0; i < n - 1; i++) {

            init(&buff2);
            init(&buff1);

            for (j = 0; j < b.size; j++) {

                carrier = 0; t = j; // shift

                for (k = 0; k < a.size; k++) {

                    buff1.h[t] = a.h[k] * b.h[j] + carrier;
                    carrier = buff1.h[t] / 10;
                    buff1.h[t] %= 10;
                    t++;

                }

                buff1.h[t] = carrier;
                buff1.size = t + ((carrier == 0) ? 0 : 1);
                //printf("==");print(&buff1);

                carrier = 0;

                int max = (buff1.size >= buff2.size) ? buff1.size : buff2.size;

                for (l = 0; l < max; l++) {
                    buff2.h[l] = buff2.h[l] + buff1.h[l] + carrier;
                    carrier = buff2.h[l] / 10;
                    buff2.h[l] %= 10;
                }
                buff2.h[l] = carrier;
                buff2.size = max + ((carrier == 0) ? 0 : 1);

                //printf(".."); print(&buff2);

                init(&buff1);

            }

            for ( j = 0; j < MAXLEN; j++)
                a.h[j] = buff2.h[j];
            a.size = buff2.size;
            a.point = a.point + b.point;

        }

        print (&a);

    }

    return 0;

}


/*
#include <iostream>

using namespace std;

const int length = 200;

typedef struct _longlong {

    int point, h[length], size;

} longlong;

void assign(longlong *a, string s) {

    int i, chk = 0;

    for (i = s.length() - 1; i >= 0; i++) {
        if (s[i] == ".") {
            a->point = i;
            chk = 1;
            continue;
        }
        a->h[i - chk] = s[i] - '0';
    }

    a->size = i - chk;


    for (i = 0; i < a->size; i++) {
        if ( i == a->point ) {
            cout << '.';
        }
        cout << a->h[i];
    }

}

int main()
{
    longlong a;
    string R;
    int n;

	while (cin >> R >> n) {

        assign( &a, R);
	    // R -> 숫자 배열형으로 컨버터

	    // R^n
	    // n번 반복
	    // ... base를 중심으로, base의 가장 낮은 자리부터 곱해나가고 그 결과를 임시로 저장
	    // ... 임시로 저장된 것들을 모두 더함. shift 잊지 말것.

	    // 결과를 출력포멧에 맞게 출력.

	}

	return 0;
}
*/