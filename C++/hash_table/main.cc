// Copyright (c) 2017 Oscar Albornoz. All rights reserved.

#include <iostream>
#include "hash_table.h"
#include <string>

using std::cout;
using std::endl;
using std::string;

size_t djb2(string str) { // NOLINT
  unsigned long hash = 5381;
    for (char c : str) {
        hash = (hash << 5) + hash + c; /* hash * 33 + c */
    }
    return hash;
}

int main() {
  HashTable<string,int> table(3,djb2);
  table.add("Oscar",1);
  table.add("Ana",2);
  table.add("Carlos",4);
  table.add("Veronica",5);
  table.add("Jose",6);
  table.add("Oscar",8);

  cout << "Debug" << endl;

  table.print_debug();

  cout << "FIND" << endl;

  cout << table.get("Oscar") << endl;
  cout << table.get("Ana") << endl;
  cout << table.get("Carlos") << endl;
  cout << table.get("Veronica") << endl;
  cout << table.get("Jose") << endl;

  cout << "Exist" << endl;

  cout << table.exists("Jose") << endl;

  cout << "Remove" << endl;

  table.remove("Ana");
  table.remove("Jose");
  table.remove("Veronica");

  cout << "Debug" << endl;

  table.print_debug();




  return 0;
}


