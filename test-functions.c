#include <math.h>
#include "test-functions.h"

// around 14 flops (3 multiplications, 1 subtraction, ~10 exponentiation)
double f(double x) {
  return exp(-x * x) - pow(x, 3);
}

// around 18 flops (5 multiplications, 1 subtraction, 2 negations, ~10 exponentiation)
double f_prime(double x) {
  return -2 * x * exp(-x * x) - 3 * x * x;
}

// around 18 flops
double g(double x) {
  return (exp(-x * x) + 2 * pow(x, 3)) / (1 + 3 * pow(x, 2));
}
