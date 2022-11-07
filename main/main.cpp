// Copyright 2022 Marina Usova

#include <stdio.h>
#include "../lib_example/example.h"
#include "matrix.h"

int main() {
  int a = 1, b = 4;
  float result;

  TDynamicVector<int> vect(10);
  vect[3] = 7;

  result = division(a, b);

  printf("%d / %d = %.2f\n", a, b, result);
  std::cout << vect[3] << std::endl << vect;
  return 0;
}
