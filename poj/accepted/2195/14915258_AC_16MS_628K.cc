#include <stdio.h>
// 2015.11.16 15:22~
const int INF = 1e9;
typedef struct _pos{
  int r, c;
} pos;
pos men[100], house[100];

int matching[100];


int edge[100][100]; // graph for hungarian method
int map[100][100]; // equality graph
bool xckd[100], yckd[100];

inline int jabs(int x) {
  return (x>=0)?x : (-x);
}
inline int jmax(int a, int b) {
  return (a>=b) ? a : b;
}
inline int jmin(int a, int b) {
  return (a<b) ? a : b;
}

bool DFS(int p, const int n) {

  for (int i =0 ; i < n; i++) { // w.r.t y (houses)
    if (!yckd[i] && map[p][i]) { // not yet visited
      yckd[i] = true;
      int t = matching[i];
      matching[i] = p;

      if (t == -1 || DFS(t, n)) return true;

      matching[i] = t;

      if (t != -1) xckd[t] = true;
    }
  }
  return false;
}
void hungarian(const int n) {
  int lx[n], ly[n];
  bool perfect = false;
  // make initial equality graph

  for (int i = 0 ; i < n; i++) {
    lx[i] = -INF;
    ly[i] = 0;
    for (int j =0; j < n; j++) {
      lx[i] = jmax(lx[i], edge[i][j]);
    }
  }

  while (!perfect) {
    // make equality graph
    for (int i =0 ;i < n; i++) {
      for (int j = 0; j < n; j++) {
        if (lx[i] + ly[j] == edge[i][j])
          map[i][j] = true;
        else
          map[i][j] = false;
      }
    }

    int cnt = 0;
    //DFS
    for (int i =0 ; i < n; i++) matching[i] = -1;

    for (int i =0 ; i < n; i++) {
      for (int j = 0; j < n; j++) xckd[j] = yckd[j] = false;

      if (DFS(i, n)) cnt++;
      else{
        xckd[i] = true;
        break;
      }
    }

    if (cnt == n) perfect = true;
    else{
      int ex = INF;
      for (int i =0 ; i < n; i++)
        for (int j = 0 ; xckd[i] && j < n; j++)
          if (!yckd[j]) ex = jmin(ex, lx[i] + ly[j] - edge[i][j]);

      for (int i = 0; i < n; i++)  {
        if (xckd[i]) lx[i] -= ex;
        if (yckd[i]) ly[i] += ex;
      }

    }



  }

}

int main() {
  int n, m;

  while (1) {
    int cost = 0;
    scanf("%d %d", &n, &m);

    if (n == 0 && m == 0) return 0;

    int mcnt = 0, hcnt = 0;
    for (int i = 0 ; i < n; i++) { // input
      char row[101];
      scanf("%s", row);
      for (int j = 0 ; j < m; j++) {
        if (row[j] == 'm') {
          men[mcnt].r = i;
          men[mcnt].c = j;
          mcnt++;
        } else if (row[j] == 'H') {
          house[hcnt].r = i;
          house[hcnt].c = j;
          hcnt++;
        }
      }
    }

    // generate a graph
    for (int i = 0; i < mcnt; i++) {
      for (int j = 0; j < hcnt; j++) {
        edge[i][j] = 0 - jabs(men[i].r - house[j].r) - jabs(men[i].c - house[j].c);
        //printf("%d ", edge[i][j]);
      }
      //printf("\n");
    }

    hungarian(mcnt);

    for (int i =0; i < mcnt; i++) cost += edge[matching[i]][i];

    printf("%d\n", -cost);
  }
  return 0;
}
