#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int gcd(int a, int b) {
  int c;
  while (b != 0) {
    c = a % b;
    a = b;
    b = c;
  }
  return a;
}

int gcd(vector<int> &v) {
  sort(v.begin(), v.end());
  int result = v[0];
  for (int i = 0; i < v.size() - 1; ++i) {
    result = gcd(result, v[i + 1]);
  }
  return result;
}

int main() {
  int n;
  cin >> n;
  vector<int> v(n);
  for (int i = 0; i < n; ++i) {
    cin >> v[i];
  }

  auto i = remove_if(v.begin(), v.end(), [&](int n) {return count(v.begin(), v.end(), n) > 1;});
  v.erase(i, v.end());
  if (v.empty())
    cout << "NA\n";
  else
    cout << gcd(v) << endl;
  return 0;
}