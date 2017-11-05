// Copyright (c) 2017 Oscar Albornoz. All rights reserved.

#include <time.h>

#include <algorithm>
#include <bitset>
#include <deque>
#include <iomanip>
#include <iostream>
#include <vector>

using namespace std;

deque<deque<int>> v1, v2;

// Oscar's algorithm
template<typename T>
void combination(int r, const deque<T> &options, deque<T> &base) {
  if (base.size() == r)
    v1.push_back(base);

  if (base.size() == r || options.empty())
    return;

  deque<T> opc(options);  // Copy options
  for (const T &i : options) {
    base.push_back(i);  // Add option to base number
    opc.pop_front();  // To does not add repeat
    combination(r, opc, base);
    base.pop_back();  // Back to original base
  }
}

// Roseta's algorithm
void comb(int N, int K) {
    vector<bool> bitmask(K, 1);  // K leading 1's
    bitmask.resize(N, 0);  // N-K trailing 0's

    // print integers and permute bitmask
    do {
        deque<int> v;
        for (int i = 0; i < N; ++i) {  // [0..N-1] integers
            if (bitmask[i]) {
              v.push_back(i);
            }
        }
        v2.push_back(v);
    } while (std::prev_permutation(bitmask.begin(), bitmask.end()));
}

template <class T>
void print(T container);

const int size = 100;

int main() {
  deque<int> arr, base = {};


  cout << fixed << endl;

  for (int i = 0; i < size; ++i)
    arr.push_back(i);

  clock_t s, e;


  s = clock();
  combination(3, arr, base);
  e = clock();
  cout << double(e-s) / CLOCKS_PER_SEC << endl;


  s = clock();
  comb(size, 3);
  e = clock();
  cout << double(e-s) / CLOCKS_PER_SEC << endl;

  cout << boolalpha << (v1 == v2) << endl;
  return 0;
}

template <class T>
void print(T container) {
  for (auto i : container)
    cout << " " << i;
  cout << endl;
}
