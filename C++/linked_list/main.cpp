// Copyright (c) 2017 Oscar Albornoz. All rights reserved.

#include <iostream>
#include "List.h"

using std::cout;
using std::endl;

int main() {
  List<int> my_list;

  my_list.push_front(2);
  my_list.push_front(1);

  my_list.push_back(4);
  my_list.push_back(5);
  my_list.push_back(6);

  my_list.insert(1, 3);

  cout << "Tamaño: " << my_list.size() << endl;

  while (my_list.size()) {
    cout << my_list.front() << endl;
    my_list.pop_front();
  }
  cout << "Tamaño: " << my_list.size() << endl;


  my_list.push_front(1);
  my_list.push_back(2);
  my_list.push_back(4);
  my_list.push_back(5);
  my_list.push_front(0);
  my_list.insert(2, 3);

  my_list.erase(0);

  while (my_list.size()) {
    cout << my_list.back() << endl;
    my_list.pop_back();
  }

  cout << "Tamaño: " << my_list.size() << endl;

  my_list.push_front(2);
  my_list.push_front(1);

  my_list.push_back(4);
  my_list.push_back(5);
  my_list.push_back(6);

  my_list.insert(1, 3);

  cout << "Tamaño: " << my_list.size() << endl;

  my_list.erase(1);
  my_list.erase(1);
  my_list.erase(1);
  my_list.erase(1);
  my_list.erase(1);
  my_list.erase(0);

  cout << "Tamaño: " << my_list.size() << endl;

  return 0;
}


