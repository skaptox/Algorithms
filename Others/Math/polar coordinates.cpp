#include <iostream>
#include <math.h>
#include <iomanip>

using namespace std;

#define PI 3.1415

void polar(double x, double y) {
  double r = sqrt(x*x + y*y);
  double a = atan(y / x) * 180 / PI;
  cout << fixed << setprecision(2);
  cout << r << ", " << a << "\n";
}

int main() {
  int n;
  double x, y;
  cin >> n;
  for (int i = 0; i < n; ++i) {
    cin >> x >> y;
    polar(x, y);
  }
  return 0;
}