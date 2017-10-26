
// http://coj.uci.cu/24h/problem.xhtml?pid=2695

/*   Input specification

The input consists of an integer N (0 < N <= 100),
the number of cases following test. For each test case, an
integer k (0 < k < 20), with the number of vectors to be added. And
the following line contain the list of vectors separated by a space. A
vector will be given by {data_1, ..., data_n}. Where n (0 < n <= 10)
and absolute value of the data will not be greater than 1000; all
integer numbers. Note that vectors could have different amount of data
values.

Output specification

For each case must return the result
of the operation, if you can not perform this operation show "No
solution" without the quotes.
Sample input
1
3
{1,2,3} {1,2,3} {1,2,3}

Sample output
{3,6,9}
*/

#include <iostream>
#include <algorithm>
#include <vector>
#include <ctype.h>
#include <string>

using namespace std;

vector<int> to_vec(string str) {
  if (str.empty())
    return {};

  str.erase(0,1);
  str.pop_back();

  string digit;
  vector<int> v;

  for (int i = 0; i < str.size(); ++i) {
    while(isdigit(str[i])) {
      digit += str[i++];
    }
    v.push_back(stoi(digit));
    digit.clear();
  }
  return v;
}

string to_str(vector<int> v) {
  string str("{");
  for (auto i : v)
    str += to_string(i) + ',';
  str.pop_back();
  str.push_back('}');
  return str;
}

vector<string> split(string str, string cut) {
  if (str.empty())
    return {};

  vector<string> v;
  size_t pos;
  while ((pos = str.find(cut)) != string::npos) {
    v.push_back(str.substr(0, pos));
    str.erase(0, pos + cut.size());
  }
  v.push_back(str);
  return v;
}

int main(int argc, char const *argv[]) {
  int n;
  cin >> n;

  for (int i = 0; i < n; ++i) {
    int k;
    cin >> k;

    string str;
    getline(cin, str);

    std::vector<string> str_vec = split(str, " ");
    std::vector<std::vector<int>> vec;
    for ( auto i : str_vec) {
      vec.push_back(to_vec(i));
    }

    auto same_size = [&](const vector<int>&v) {return v.size() == vec[0].size();};

    if (all_of(vec.begin(), vec.end(), same_size)) {
      std::vector<int> vec_sol;
      for (int i = 0; i < vec[0].size(); ++i) {
        int c = 0;
        for (int j = 0; j < k; ++j) {
          c += vec[j][i];
        }
        vec_sol.push_back(c);
      }
      cout << to_str(vec_sol) << endl;
    } else {
      cout << "No solution" << endl;
    }
  }
  return 0;
}