#include <iostream>
#include <algorithm>

using namespace std;

int main(int argc, char const *argv[])
{
  int n;
  cin >> n;
  cin.ignore();

  for (int i = 0; i < n; ++i) {
    string s, p;

    getline(cin, p);
    size_t pos = p.find(' ');

    if (pos != string::npos) {
      s = p.substr(0, pos);
      p.erase(0, pos + 1);
    }

    if (is_permutation(s.begin(), s.end(),p.begin()))
      cout << "YES" << endl;
    else
      cout << "NO" << endl;
  }
  return 0;
}