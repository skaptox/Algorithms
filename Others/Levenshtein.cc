// Copyright (c) 2017 Oscar Albornoz. All rights reserved.

#include <iostream>
#include <algorithm>

/*

  In information theory, Linguistics and computer science, the Levenshtein
  distance is a string metric for measuring the difference between two
  sequences. Informally, the Levenshtein distance between two words is the
  minimum number of single-character edits (insertions, deletions or
  substitutions) required to change one word into the other. It is named after
  Vladimir Levenshtein, who considered this distance in 1965

  https://www.youtube.com/watch?v=We3YDTzNXEk&t=194s

*/

using std::cout;
using std::endl;

int levenshtein(std::string s1, std::string s2) {
  if (s1.empty())
    return s2.size();

  if (s2.empty())
    return s1.size();

  int col = s1.size() + 1;
  int row = s2.size() + 1;

  int mx[row][col];

  for (int i = 0; i < col; ++i)
    mx[0][i] = i;

  for (int i = 0; i < row; ++i)
    mx[i][0] = i;


  for (int r = 1; r < row; ++r) {
    for (int c = 1; c < col; ++c) {
      if (s1[c-1] == s2[r-1]) {
        mx[r][c] = mx[r-1][c-1];
      } else {
        mx[r][c] = std::min({mx[r-1][c-1], mx[r-1][c], mx[r][c-1]}) + 1;
      }
    }
  }

  return mx[row - 1][col - 1];

  /*
  for (int i = 0; i < row; ++i)
  {
    for (int j = 0; j < col; ++j)
      cout << mx[i][j] << " ";
    cout << endl;
  }
  */
}

int main() {
  cout << levenshtein("abcdef", "azced") << endl;
  return 0;
}
