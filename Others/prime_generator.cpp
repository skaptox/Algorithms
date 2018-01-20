// Copyright (c) 2017 Oscar Albornoz. All rights reserved.

#include <math.h>
#include <iostream>

using std::cout;
using Ull = unsigned long long;

void sieve_of_eratosthenes(Ull n) {
  const size_t kSize = n + 1;
  bool primes[kSize];
  std::fill(primes, primes + kSize, true);
  for (int i = 2; i <= sqrt(n); ++i) {
    if (primes[i] == true) {
      for (int j = i * 2; j < kSize; j += i) {
        primes[j] = false;
      }
    }
  }

  for (int i = 2; i < kSize; ++i) {
    if (primes[i] == true) {
      cout << i << ", ";
    }
  }
  cout << '\n';
}

int main() {
  sieve_of_eratosthenes(100);
  return 0;
}

