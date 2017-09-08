#include <stdio.h>

int is_power_two(int number) {
  return number && !(number & (number - 1));
}

int main(int argc, char const *argv[]) {
  printf("Power of 2\n");
  for (int i = 0; i <= 1024; ++i){
    if (is_power_two(i)) {
      printf("%i,",i);
    }
  }

  printf("\n");

  int bit_fld = 8;
  int n = 3;

  printf("Set a bit\n");
  printf("%i\n", bit_fld | (1 << n));


  printf("Clear a bit\n");
  printf("%i\n", bit_fld & ~(1 << n));


  printf("Toggle a bit\n");
  printf("%i\n", bit_fld ^ (1 << n));


  printf("Test a bit\n");
  printf("%i\n", bit_fld & (1 << n));


  return 0;
}