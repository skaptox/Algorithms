// Copyright (c) 2017 Oscar Albornoz. All rights reserved.

#include <time.h>

#include <algorithm>
#include <bitset>
#include <vector>
#include <iomanip>
#include <iostream>
#include <vector>

using namespace std;

template <class T>
void print(T container) {
  for (auto i : container)
    cout << " " << i;
  cout << endl;
}


const int size = 2;

template<typename T>
void combination(const vector<T> &options, vector<T> base = {}, int l = 0) {
  if (base.size() == size) {
    print(base);
  }

  if (base.size() == size || options.empty())
    return;

  for (int i = l; i < options.size(); ++i) {
    base.push_back(options[i]);
    combination(options, base, i + 1);
    base.pop_back();
  }
}

template <class T>
void print(T container);

int main() {
  vector<char> arr = {'a','b','c','d','e'};
  combination(arr);
  return 0;
}


