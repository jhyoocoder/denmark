// Swamp.cpp : Defines the entry point for the console application.
//

#include <iostream>
#include <functional>
#include <vector>
#include <algorithm>
#include <cstring>
#include <cmath>

using namespace std;

const int SIZE = 1000;

struct point {
	int x, y;
} points[SIZE];

int npoints;

typedef struct _Line {
	int count;
	double a, b;
} Line;

bool compareLine( const Line &l1, const Line &l2) {
	if (l1.a > l2.a) return true;
	else if (l1.a == l2.a) return (l1.b > l2.b);
	return false;
}

vector<Line> lines;
int lineNum[SIZE];
int sorting[SIZE*SIZE];

int main() // O(n^2 log n) is also TLE
{
	int i, j, k, icase=0;
	cin >> npoints;
	while (npoints != 0) {
		icase++;
		for(i=0; i<npoints; i++) {
			cin >> points[i].x >> points[i].y;
		}
		int max = 0, lcount = 0;
		lines.clear();
		for(i=0; i<npoints-1; i++) {
			for(j=i+1; j<npoints; j++) {
				lcount++;
				// determine eqn ax+by=c
				double a = points[i].y - points[j].y;
				double b = points[j].x - points[i].x;
				double c = points[j].x*points[i].y - points[j].y*points[i].x;
				Line l;
				l.a = a/c; l.b = b/c; l.count = lcount; //2 points
				lines.push_back(l);
			}
		}
		//Radix sorting
		sort(lines.begin(), lines.end(), compareLine );
		
		vector<Line>::iterator iter;
		int count = 1;
		for (iter = lines.begin(); iter != lines.end(); iter++) {
			if (iter->a == (iter+1)->a && iter->b == (iter+1)->b) {
				count++;
			} else {
				if (max < count) max = count;
				else count = 1;
			}
		}
		
		if (max >= 4)
			cout << "Photo " << icase << ": " << (int)((sqrt(8*max+1)+1)/2) << " points eliminated" << endl;
		else
			cout << "Photo " << icase << ": 0 points eliminated" << endl;
		cin >> npoints;
	}
	return 0;
}