#include <math.h>
#include "test-functions.h"

double f(double x) {
  return exp(-x * x) - pow(x, 3);
}

double f_prime(double x) {
  return -2 * x * exp(-x * x) - 3 * x * x;
}

double g(double x) {
  return sqrt(1 + 2 / x);
}
