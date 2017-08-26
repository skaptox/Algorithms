// Copyright (c) 2017 Oscar Albornoz. All rights reserved.

#include <iostream>
#include "List.h"

using namespace std;

int main() {
  List<int> my_list;

  for (int i = 0; i < 1000; ++i)
  {
    my_list.push_back(i);
  }

  cout << "Tamaño: " << my_list.size() << endl;


  while(my_list.size()) {
    my_list.pop_back();
  }

  cout << "Tamaño: " << my_list.size() << endl;

  cout << "Dale a tu cuerpo energia macarena"<<endl;

  return 0;
}


