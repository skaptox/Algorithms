#include <iostream>
#include <algorithm>

using namespace std;

void permute(string &str, int l, int r) {
   if ( l == r) {
      cout << str << endl;
   } else {
      for (int i = l; i <= r ; i++) {
         swap(str[l], str[i]);
         permute(str, l + 1, r);
         swap(str[l], str[i]);
      }
   }
}

void permutation(string &str) {
   sort(str.begin(),str.end());
   do {
      cout << str << endl;
   } while(next_permutation(str.begin(),str.end()));
}

int main() {
   string str = "123";
   permute(str, 0, str.size() - 1);
}
