#include "arith.h"
#include "compare.h"
#include "control.h"
#include "eval.h"

#include <assert.h>
#include <stdio.h>
#include <string.h>

/* IIF test begin */
#define A 0
#define B 2
#define Y 3
#define X 1

#if (IIF(X)(A, B) != A)
#error "IIF(X)(A, B) was expanded incorrectly"
#endif

#if (IIF(0)(X, Y) != Y)
#error "IIF(0)(X, Y) was expanded incorrectly"
#endif

#if (IIF(INV(X))(A, B) != B)
#error "IIF(INV(X))(A, B) was expanded incorrectly"
#endif

#undef X
#undef Y
#undef B
#undef A
/* IIF test end */

/* NOT test begin */
#if (NOT(0) != 1)
#error "NOT(0) was expanded incorrectly"
#endif

#if (NOT(T) != 0)
#error "NOT(T) was expanded incorrectly"
#endif
/* NOT test end */

/* IF test begin */
#define A 0
#define B 1
#define T 1

#if (IF(0)(A, B) != B)
#error "IF(0)(A, B) was expanded incorrectly"
#endif

#if (IF(T)(A, B) != A)
#error "IF(T)(A, B) was expanded incorrectly"
#endif

#if (IF(K)(A, B) != A)
#error "IF(K)(A, B) was expanded incorrectly"
#endif

#undef T
#undef B
#undef A
/* IF test end */

/* WHEN test begin */
#if INV(IS_PAREN(WHEN(0)(LEFT, RIGHT)()))
#error "WHEN(0)(LEFT, RIGHT) was expanded incorrectly"
#endif

#define NEQ_LEFT(X) X
#define NEQ_RIGHT(X) X
#define CHECKER(X, Y) BITAND(EQ(X, LEFT))(EQ(Y, RIGHT))
#define HELPER CHECKER
#define ARGS (WHEN(K)(LEFT, RIGHT))

#if INV(EXPAND(HELPER ARGS))
#error "WHEN(K)(LEFT, RIGHT) was expanded incorrectly"
#endif

#undef ARGS
#undef HELPER
#undef CHECKER
#undef NEQ_RIGHT
#undef NEQ_LEFT
/* WHEN test end */

/* DEFER test begin */

#define A(...) 1,
#define CHECKER(X, Y) BITAND(X)(INV(Y))
#define ARGS (EXPAND(DEFER(A)() 0))
#define HELPER CHECKER
#if INV(EXPAND(HELPER ARGS))
#error "EXPAND(DEFER(A)()) was expanded incorrectly"
#endif

#undef HELPER
#undef ARGS
#undef CHECKER
#undef A

/* DEFER test end */

void defer_test(void) {
#define A(...) 1,
#define TO_STR(...) #__VA_ARGS__
  assert(strcmp(TO_STR(DEFER(A)), "DEFER(A)") == 0 &&
         "DEFER(A) was expanded incorrectly");
#undef TO_STR
#undef A
  puts("defer_test passed!");
}

void repeat_test(void) {
#define M(i, _) i,
  const int VARS[] = {EVAL(REPEAT(8, M, ~))}; /* 0 1 2 3 4 5 6 7 */
  for (int i = 0; i < 8; ++i) {
    assert(i == VARS[i] && "REPEAT(8, M, ~) was expanded incorrectly");
  }
#undef M
  puts("repeat_test passed!");
}
