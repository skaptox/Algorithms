#include <iostream>
#include <algorithm>
#include <map>
#include <time.h>

using namespace std;

int main(int argc, char const *argv[])
{
  int n;
  cin >> n;
  cin.ignore(256, '\n');

  for (int i = 0; i < n; ++i) {
    string s, p;
    cin >> s >> p;

    if (s.size() != p.size()) {
      cout << "NO" << endl;
      continue;
    }

    bool equal;
    for (int i = 0; i < s.size(); ++i) {
      equal = false;
      int L = s.size();
      swap(s[i], s[L-i-1]);

      if (s == p) {
        equal = true;
        break;
      }

      swap(s[i], s[L-i-1]);
    }
    cout << (equal ? "YES" : "NO") << endl;
  }

  return 0;
}