/*
  1) Backtracking 시 st +1 -> i+1... 실수.. 어쩐지 중복되더라
  2) 중복되는 경우를 안빼줌. break로써 제외.(preprocessing)
  3) C 컴파일러 -> 변수 선언은 반드시 코드의 맨 처음



*/

#include <stdio.h>
#include <string.h>

#define MAXN 110
#define MAXLEN 20

int n;
char iWord[MAXN][MAXLEN];

int m, lenOfAcronym;
char aWord[MAXN][MAXLEN];
int lenOfaWord[MAXN];

int result;



void pproc(char *acronym, char *fullname) {
    char *ptr, lacro[MAXLEN];
    int len, i, j, k, isIgnored;

    strcpy(lacro, acronym);
    strlwr(lacro);
    m = 0;


    ptr = strtok(fullname, " ");
    do {
        if (ptr) {

            //printf("PP : %s\n", ptr);

            isIgnored = 0;

            for (i = 0; i < n; i++)
                if ( strcmp(ptr, iWord[i]) == 0 ) {
                    isIgnored = 1;
                    break;
                }

            if (!isIgnored) {
                len = strlen(ptr);
                k = 0;

                for (i = 0; i < len; i++) {
                    for(j = 0; j < lenOfAcronym; j++)
                        if ( ptr[i] == (acronym[j] - 'A'+'a') ) {
                            aWord[m][k] = ptr[i] - 'a' + 'A';
                            k++;
                            break;
                        }
                }
                lenOfaWord[m] = k;
                m++;
            }
        }
        ptr = strtok(NULL, " ");
    } while (ptr != NULL);

}

void find(char *acro, int index1, int index2, int st, int depth) {
    //int k;

    //for (k =0; k < depth; k++) printf("..");
    //printf("(%d %d %d / %d, %d)\n", index1, index2, st, lenOfAcronym - index1, m - index2);

    if ( lenOfAcronym - index1 >= m - index2) {

        if ( lenOfAcronym == index1 ) {
            result++;
      //      printf("...(%d %d %d) : %d\n", index1, index2, st, result);
            return 0;
        }

        int i;

        for (i = st; i < lenOfaWord[index2]; i++) {
            if ( acro[index1] == aWord[index2][i] ) {
                find (acro, index1 + 1, index2 , i + 1,depth+1);
                find (acro, index1 + 1, index2 + 1, 0,depth+1);
            }
        }

    }
}

int main() {

  int i, j;

  while (scanf("%d", &n) != EOF) {

    if ( n == 0 ) break;

    char acronym[MAXLEN], fullname[MAXLEN*10];

    for (i = 0 ; i < n; i++)
      scanf("%s",iWord[i]);

    do {
        result = 0;

        scanf("%s", acronym); lenOfAcronym = strlen(acronym);
        gets(fullname);

        if ( strcmp(acronym, "LAST") == 0 && strcmp(fullname,"CASE") == 0) break;

        pproc(acronym, fullname);

        for (i = 0; i < m; i++ ) {
            for (j = 0; j < lenOfaWord[i]; j++)
                printf("%c",aWord[i][j]);
            printf("\n");
        }
        find(acronym, 0, 0, 0, 0);

        if (result > 0)
            printf("%s can be formed in %d ways", acronym, result);
        else
            printf("%s is not a valid abbreviation", acronym);

    } while (1);

  }

  return 0;
}

