// Copyright (c) 2017 Oscar Albornoz. All rights reserved.

#include <iostream>
#include <vector>
#include <numeric>
#include <array>
#include <functional>

using namespace std;

using Ull = unsigned long long;
vector<vector<Ull>> global_vec;

void combinations(Ull p, vector<Ull> opciones, vector<Ull> base = {}) {
  Ull sum = 0;
  auto i = base.begin();
  while(sum < p && i != base.end()) {
    sum += *i;
    ++i;
  }

  if (sum <= p) {
    global_vec.push_back(base);
  } else return;

  vector<Ull> opc = opciones;
  for (const auto &i : opciones) {
    opc.erase(opc.begin());

    vector<Ull> b = base;
    b.push_back(i);

    combinations(p, opc, b);
  }
}

int main(int argc, char const *argv[])
{
  int n;
  Ull p;
  cin >> n >> p;

  vector<Ull> warlocks;
  int wp;

  for (int i = 0; i < n; ++i) {
    cin >> wp;
    warlocks.push_back(wp);
  }

  combinations(p, warlocks);
  cout << global_vec.size() - 1 << endl;
  return 0;
}