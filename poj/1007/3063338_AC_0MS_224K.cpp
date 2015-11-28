#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

const int mlength = 50, maxn = 100;

char DNA[maxn + 1][mlength + 1];
int ordered[maxn + 1];

int n, m; // length & the number

void calculate( int k ) {

    ordered[k] = 0;

    for (int i = 0; i < n - 1; i++)
        for (int j = i + 1; j < n; j++)
            if ( DNA[k][i] > DNA[k][j] )
                ordered[k] ++;

}

bool comp(const int &a, const int &b) {
    return ordered[b] > ordered[a];
}

int main() {

    int result[maxn + 1], i;

    cin >> n >> m;

    for (i = 0; i < m; i++) {
        cin >> DNA[i];
        calculate(i);
        result[i] = i;
    }

    sort( result, result + m, comp);

    for (i = 0; i < m; i++)
        cout << DNA[result[i]] << endl;

    return 0;
}
