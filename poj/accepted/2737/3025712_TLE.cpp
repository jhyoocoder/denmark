// Swamp.cpp : Defines the entry point for the console application.
//

#include <iostream>
using namespace std;

const int SIZE = 1000;

struct point {
	int x, y;
} points[SIZE];
int npoints;

int main()
{
	int i, j, k, icase=0;
	cin >> npoints;
	while (npoints != 0) {
		icase++;
		for(i=0; i<npoints; i++) {
			cin >> points[i].x >> points[i].y;
		}
		int max = 0;
		for(i=0; i<npoints-2; i++) {
			for(j=i+1; j<npoints-1; j++) {
											// determine eqn ax+by=c
				int a = points[i].y - points[j].y;
				int b = points[j].x - points[i].x;
				int c = points[j].x*points[i].y - points[j].y*points[i].x;
				int count = 2;
				for(k=j+1; k<npoints; k++) {
					if (a*points[k].x + b*points[k].y == c) {
						count++;
					}
				}
				if (count > max)
					max = count;
			}
		}
		if (max >= 4)
			cout << "Photo " << icase << ": " << max << " points eliminated" << endl;
		else
			cout << "Photo " << icase << ": 0 points eliminated" << endl;
		cin >> npoints;
	}
	return 0;
}
