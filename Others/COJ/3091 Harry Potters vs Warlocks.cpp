// Copyright (c) 2017 Oscar Albornoz. All rights reserved.

#include <iostream>
#include <deque>
#include <numeric>
#include <array>
#include <functional>
#include <algorithm>

using namespace std;

using Ull = unsigned long long;
Ull sets = 0;

void combinations(const Ull &p, const deque<Ull> &options, deque<Ull> &base) {
  Ull sum = 0;

  for (int i = 0; i < base.size(); ++i) {
    sum += base[i];
  }

  if (sum <= p) {
    sets++;
  } else return;

  deque<Ull> opc(options);
  for (int i = 0; i < options.size(); ++i) {
    opc.pop_front();
    base.push_back(options[i]);
    combinations(p, opc, base);
    base.pop_back();
  }
}

int main(int argc, char const *argv[]) {
  int n;
  Ull p;
  cin >> n >> p;

  deque<Ull> warlocks;
  int wp;

  for (int i = 0; i < n; ++i) {
    cin >> wp;
    warlocks.push_back(wp);
  }

  deque<Ull> base;
  combinations(p, warlocks, base);
  cout << sets - 1 << endl;

  return 0;
}
