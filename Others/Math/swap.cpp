#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
  int n;
  cin >> n;
  int a[n];
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }

  for (int i = 0; i < n - 1; ++i) {
    if (a[i] > a[i+1]) {
      for (int j = n - 1; j > i; --j) {
        if (a[j-1] > a[j]) {
          swap(a[i], a[j]);
          break;
        }
      }
      break;
    }
  }

  if (is_sorted(a, a+n))
    cout << "YES\n";
  else
    cout << "NO\n";
}