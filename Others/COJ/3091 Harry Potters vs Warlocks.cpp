// Copyright (c) 2017 Oscar Albornoz. All rights reserved.

#include <iostream>
#include <vector>
#include <numeric>
#include <array>
#include <functional>
#include <algorithm>

using namespace std;

using Ull = unsigned long long;
vector<vector<Ull>> global_vec;

void combinations(Ull p, const vector<Ull> &options, vector<Ull> &base) {
  Ull sum = 0;

  for (int i = 0; i < base.size(); ++i) {
    sum += base[i];
  }

  if (sum <= p) {
    global_vec.push_back(base);
  } else return;

  vector<Ull> opc(options);
  for (int i = 0; i < options.size(); ++i) {
    opc.erase(opc.begin());
    vector<Ull> b(base);
    b.push_back(options[i]);
    combinations(p, opc, b);
  }
}

int main(int argc, char const *argv[]) {
  int n;
  Ull p;
  cin >> n >> p;

  vector<Ull> warlocks;
  int wp;

  for (int i = 0; i < n; ++i) {
    cin >> wp;
    warlocks.push_back(wp);
  }

  vector<Ull> base;
  combinations(p, warlocks, base);
  cout << global_vec.size() - 1 << endl;

  return 0;
}