#include <stdio.h>
#include <stdlib.h>

#define PI 3.141592

int main() {
	int i, year, n;
	double x, y, r2;
	double area, r2area;

	scanf("%d", &n);

	for (i = 0; i < n; i++) {
		scanf("%lf %lf", &x, &y);
		r2 = x*x + y*y;

		year = 1;
		area = 0.0;
		r2area = 0.0;

		while(r2 > r2area) { /* Hint 1.*/
			year ++;
			area += (double)50.0;
			r2area = 2 * area / PI;

		}

		printf("Property %d: This property will begin eroding in year %d.\n", i+1, year - 1);
	}
	printf("END OF OUTPUT.\n");
	return 0;
}