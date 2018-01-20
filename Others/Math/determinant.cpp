#include <iostream>

using namespace std;

int determinant(int m[][3]) {
  return m[0][0] * ((m[1][1] * m[2][2]) - (m[2][1] * m[1][2])) -
    m[0][1] * ((m[1][0] * m[2][2]) - (m[2][0] * m[1][2])) +
    m[0][2] * ((m[1][0] * m[2][1]) - (m[2][0] * m[1][1]));

}

int main() {
  int matrix[3][3];

  int n;
  for (int f = 0; f < 3; ++f)
    for (int c = 0; c < 3; ++c)
      cin >> matrix[f][c];
  cout << determinant(matrix) << "\n";
  return 0;
}