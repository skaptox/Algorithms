// Copyright (c) 2017 Oscar Albornoz. All rights reserved.

#include <iostream>
#include "Vector.h"

using std::cout;
using std::endl;

int main() {
  Vector<int> vec;

  bool state;
  vec.push(0);
  for (int i = 0; i < 100; ++i)
  {
    state = !state;
    vec.insert(0,state);
  }

  vec.remove(0);

  for (int i = 0; i < vec.size(); ++i)
    cout << vec.at(i) << ",";
  cout << endl;


  return 0;
}
