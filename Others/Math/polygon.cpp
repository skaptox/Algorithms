#include <iostream>
#include <math.h>
#include <iomanip>

using namespace std;

int determinant(int m[][3]) {
  return m[0][0] * ((m[1][1] * m[2][2]) - (m[2][1] * m[1][2])) -
    m[0][1] * ((m[1][0] * m[2][2]) - (m[2][0] * m[1][2])) +
    m[0][2] * ((m[1][0] * m[2][1]) - (m[2][0] * m[1][1]));
}

struct point {
  int x, y;
};

double area(point *a, int n) {
  double r = 0;
  for (int i = 0; i < n; ++i) {
    int j = i + 1;
    if (j == n)
      j = 0;

    int m[3][3] = {{0,a[i].x,a[j].x},
                   {0,a[i].y,a[j].y},
                   {1,1,1}};
    r += abs(0.5 * determinant(m));
  }
  return r;
}

int main() {
  int n;
  cin >> n;

  point p[n];
  for (int i = 0; i < n; ++i) {
    cin >> p[i].x >> p[i].y;
  }

  cout << fixed << setprecision(2);
  cout << area(p, n) << "\n";
  return 0;
}