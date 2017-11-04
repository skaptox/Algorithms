#include <iostream>
#include <math.h>
#include <iomanip>
#include <algorithm>
#include <vector>
#include <tuple>
#include <utility>

using namespace std;

struct Point {
  int x, y;
  Point() = default;
  Point(int _x, int _y) : x(_x), y(_y) {};
  
  bool operator<(const Point &rhs) {
    return tie(x, y) < tie(rhs.x, rhs.y);
  }
};

double distance(Point &p1, Point &p2) {
  return sqrt(pow(p2.x - p1.x, 2) + 
    pow(p2.y - p1.y, 2));
}

double distance(vector<Point> &v) {
  double dis = 0;
  for(int i = 1; i < v.size(); ++i) {
    dis += distance(v[i - 1], v[i]);
  }
  return dis;
}

int main() {
  int n;
  cin >> n;
  int x, y;
  vector<Point> v;
  for (int i = 0; i < n; ++i) {
    cin >> x >> y;
    v.push_back(Point(x,y));
  }
  cout << fixed << setprecision(2);
  
  double min = distance(v);
  while(next_permutation(v.begin(), v.end())) {
  double d = distance(v);
  if (d < min)
    min = d;
  }
  cout << min << endl;
  return 0;

}
