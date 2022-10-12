// Copyright 2022 Maxim Filatov

#include <stdio.h>
#include "../lib_example/example.h"

void main() {
  int a = 1, b = 4;
  float result;

  result = plus(a, b);

  printf("%d + %d = %.2f\n", a, b, result);
}
