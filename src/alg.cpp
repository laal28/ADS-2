// Copyright 2022 NNTU-CS
#include <cstdint>
#include "alg.h"


double pown(double value, uint16_t n) {
  double p = 1;
  for ( ; n > 0; --n )
    p *= value;
  return p;
}

uint64_t fact(uint16_t n) {
  uint64_t r = 1;
  for ( uint16_t i = 2; i <= n; i++ )
    r *= i;
  return r;
}

double calcItem(double x, uint16_t n) {
  return pown( x, n ) / fact(n);
}

double expn(double x, uint16_t count) {
  double exp = 2;
  for ( ; count > 1; count-- )
    exp += calcItem(x, count);
  return exp;
}

double sinn(double x, uint16_t count) {
  double s = x;
  for ( ; count > 1; count-- )
    s += pown(-1, count - 1) * calcItem(x, 2 * count - 1);
  return s;
}

double cosn(double x, uint16_t count) {
  double s = 1;
  for ( ; count > 1; count-- )
    s += pown(-1, count - 1) * calcItem(x, 2 * count - 2);
  return s;
}
