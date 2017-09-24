#include <iostream>

#include <chrono>

using namespace std;

unsigned long long sum_stack(unsigned long long num) {
  if (num == 0)
    return 0;
  return num + sum_stack(num - 1);
}

unsigned long long sum_tail(unsigned long long num, unsigned long long accumulate = 0) {
  if (num == 0)
    return accumulate;
  else
   sum_tail(num - 1, num + accumulate);
}

int main(int argc, char const *argv[])
{
  if (argc < 2) {
    cerr << "Missing a argument" << endl;
    return 0;
  }

  clock_t a,b;
  a = clock();
  cout << "Tail: " << sum_tail(atoi(argv[1])) << endl;
  b = clock();
  cout << (double)(b-a) / CLOCKS_PER_SEC << endl;

  a = clock();
  cout << "Stack: " << sum_stack(atoi(argv[1])) << endl;
  b = clock();
  cout << (double)(b-a) / CLOCKS_PER_SEC << endl;
  return 0;
}