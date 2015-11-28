// Swamp.cpp : Defines the entry point for the console application.
//

#include <iostream>
#include <functional>
#include <set>


using namespace std;

const int SIZE = 1000;

struct point {
	int x, y;
} points[SIZE];

int npoints;

class Line {
public:
	Line() {}
	~Line() {}

	double a, b;
};

template< typename T >
struct compareLine : public binary_function<T, T, bool>
{
	bool operator() (const T& l1, const T &l2) const {
		if (l1.a < l2.a) return true;
		else if (l1.a == l2.a) return (l1.b < l2.b);
		return false;
	}
};

set<Line, compareLine<Line> > lines;

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
		lines.clear();
		for(i=0; i<npoints-1; i++) {
			for(j=i+1; j<npoints; j++) {
				// determine eqn ax+by=c
				double a = points[i].y - points[j].y;
				double b = points[j].x - points[i].x;
				double c = points[j].x*points[i].y - points[j].y*points[i].x;
				Line l;
				l.a = a/c; l.b = b/c;
				lines.insert(l);				
			}
		}
		set<Line, compareLine<Line> >::iterator iter;
		for (iter = lines.begin(); iter != lines.end(); iter++) { // for each line,
			int count = 0;
			for(k=0; k<npoints; k++) {
				if (iter->a*points[k].x + iter->b*points[k].y == 1.0) {
					count++;
				}
			}
			if (count > max)
				max = count;
		}
		if (max >= 4)
			cout << "Photo " << icase << ": " << max << " points eliminated" << endl;
		else
			cout << "Photo " << icase << ": 0 points eliminated" << endl;
		cin >> npoints;
	}
	return 0;
}