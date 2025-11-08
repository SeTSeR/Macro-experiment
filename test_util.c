#include "util.h"

#include <assert.h>
#include <stdio.h>

void cat_test() {
  const int CAT(A, B) = 3;
  assert(AB == 3 && "Macro CAT(A, B) was expanded incorrectly");

#define X 1
  const int CAT(B, X) = 4;
  assert(B1 == 4 && "Macro CAT(B, X) was expanded incorrectly");
#undef X

  puts("cat_test passed!");
}
