#include "power.h"

long double power_iter(double x, int n) {
  long double result = 1;
  for (int i = 0; i < n; i++) {
    result *= x;
  }
  return result;
}

long double power_rec(double x, int n) {
  if (n == 0) return 1;
  return x * power_rec(x, n - 1);
}

long double power_half(double x, int n) {
  if (n == 0) return 1;
  long double half = power_half(x, n / 2);
  if (n % 2 == 0) {
    return half * half;
  } else {
    return x * half * half;
  }
}
