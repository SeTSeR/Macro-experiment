#include "arith.h"
#include "control.h"

#include <assert.h>
#include <stdio.h>

void iif_test(void) {
  const int A = 0;
  const int B = 2;
  const int Y = 3;
#define X 1
  assert(IIF(X)(A, B) == A && "IIF(X)(A, B) was expanded incorrectly");
  assert(IIF(0)(X, Y) == Y && "IIF(0)(X, Y) was expanded incorrectly");

  assert(IIF(INV(X))(A, B) == B && "IIF(INV(X))(A, B) was expanded incorrectly");
#undef X
  puts("iif_test passed!");
}

void not_test(void) {
  assert(NOT(0) == 1 && "NOT(0) was expanded incorrectly");
  assert(NOT(T) == 0 && "NOT(T) was expanded incorrectly");
  puts("not_test passed!");
}

void if_test(void) {
  const int A = 0;
  const int B = 1;
  #define T 1
  assert(IF(0)(A, B) == B && "IF(0)(A, B) was expanded incorrectly");
  assert(IF(T)(A, B) == A && "IF(T)(A, B) was expanded incorrectly");
  assert(IF(K)(A, B) == A && "IF(K)(A, B) was expanded incorrectly");
  #undef T
  puts("if_test passed!");
}

void when_test(void) {
  puts("when_test passed!");
}

void defer_test(void) {
  puts("defer_test passed!");
}

void repeat_test(void) {
  puts("repeat_test passed!");
}
