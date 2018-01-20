#include <iostream>
#include <math.h>

using namespace std;

int determinant(int m[][3]) {
  return m[0][0] * ((m[1][1] * m[2][2]) - (m[2][1] * m[1][2])) -
    m[0][1] * ((m[1][0] * m[2][2]) - (m[2][0] * m[1][2])) +
    m[0][2] * ((m[1][0] * m[2][1]) - (m[2][0] * m[1][1]));
}

struct point {
  int x, y;
};

int collinear(point *p, int n) {
  int greater = 2;
  for (int i = 0; i < n; ++i) {
    for (int j = i+1; j < n; ++j) {
      int count = 2;
      for(int k = 0; k < n; ++k) {
        if (k == i || k == j)
          continue;

        int c[3][3] = {{p[i].x, p[j].x, p[k].x},
                       {p[i].y, p[j].y, p[k].y},
                       {1, 1, 1}};
        double area = 0.5 * determinant(c);
        if (area == 0)
          count++;
      }
      greater = max(greater, count);
    }
  }
  return greater;
}

int main() {
  int n;
  cin >> n;

  point p[n];
  for (int i = 0; i < n; ++i) {
    cin >> p[i].x >> p[i].y;
  }
  cout << collinear(p, n) << "\n";

  return 0;
}