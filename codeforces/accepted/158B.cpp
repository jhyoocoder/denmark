#include <iostream>

using namespace std;

const int cmax = 4+1;
int pop[cmax];

inline int relu(int x){
	return (x >= 0) ? x : 0;
}

int main() {
	int n, i, p;
	cin >> n;

	for (i =0 ; i < n; i++)	{
		cin >> p;
		pop[p]++;
	}
	int alpha = relu(pop[1] - (pop[3] + 2 * (pop[2]&1)));
	cout << pop[4] + pop[3] + (pop[2]>>1) + (pop[2]&1) + alpha/4 + (alpha%4!=0) << endl;
	return 0;
}
