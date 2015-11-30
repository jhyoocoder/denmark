#include <iostream>
#include <cmath>

using namespace std;

long double jabs(long double x) {
  return (x >= 0.0) ? x : -x;
}

int main() {
  long double x1, y1, r1, x2, y2, r2;
  long double area = 0.0;
  cin >> x1 >> y1 >> r1;
  cin >> x2 >> y2 >> r2;
  cout.precision(20);
  cout.setf(ios_base::showpoint);
  long double d;

  d = sqrtl((x1-x2)*(x1-x2) + (y1-y2)*(y1-y2));
  if ( d < r1 + r2 ) { // they have intersection
    if (d > jabs(r1 - r2)) {
      long double theta1, theta2, x, h, s1,s2;
      x = (r2*r2 - r1*r1 + d*d) / 2.0 / d;
      theta1 = acos((d-x)/r1); theta2 = acos(x/r2);
      //h = sqrtl(r2*r2 - x*x);
      //s1 = sqrtl(1 - (d-x)*(d-x)/r1/r1);
      //s2 = sqrtl(1 - x*x/r2/r2);
      //s1 = sqrtl((r1*r1 - (d-x)*(d-x))/r1/r1);
      //s2 = sqrtl((r2*r2 - x*x)/r2/r2);
      area = (r1 * r1 * theta1 - r1 * sin(theta1) * (d-x) + r2 * r2 * theta2 - r2 * sin(theta2) * x); // ok
      //area = (r1 * r1 * theta1 - r1 * s2 * (d-x) + r2 * r2 * theta2 - r2 * s2 * x); // ok
      //area = (r1 * r1 * theta1 + r2 * r2 * theta2) - d * h;
      //area = (r1 * r1 * theta1 - r1 * r1 * sin(theta1) * cos(theta1) + r2 * r2 * theta2 - r2 * r2 * sin(theta2) * cos(theta2));

    } else { // one eats the other
      if (r1 > r2) {
        area = acos(-1) * r2 * r2;
      } else {
        area = acos(-1) * r1 * r1;
      }
    }
  }

  cout << area << endl;
  return 0;
}
