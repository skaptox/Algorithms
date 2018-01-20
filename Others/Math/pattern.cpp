#include <iostream>
#include <string>
#include <bitset>

using namespace std;

int main() {
  int n;
  cin >> n;
  string str = bitset<64>(n).to_string();
  auto i = str.find('1');
  str.erase(0, i);
  string tmp(str, 1);
  tmp += str;
  tmp += str[0];
  cout << str.length() / (tmp.find(str) + 1) << "\n";

  return 0;
}

