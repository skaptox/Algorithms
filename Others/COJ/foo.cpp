#include <iostream>
#include <math.h>

using namespace std;

int main(int argc, char const *argv[])
{
  int i, sum = 0;
  cin >> i;
  int n = i;

  if (n < 0) {
    n *= -1;
  }

  for (int i = 1; i <= n; ++i) {
    sum += i;
  }

  if (i < 0) {
    sum -= 1;
    sum = -1 * sum;
  }

  cout << sum << endl;
  return 0;
}