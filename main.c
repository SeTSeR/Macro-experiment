#include "test.h"

#include <stdio.h>

/* WHEN(0)(LEFT, RIGHT) */
/* WHEN(K)(LEFT, RIGHT) */

/* #define A(...) 1,  */
/* #define B(...) A(__VA_ARGS__) */
/* DEFER(A)() */
/* EXPAND(DEFER(A)()) */

/* EVAL(REPEAT(4, F, 1)) */
/* #define M(i, _) i */
/* EVAL(REPEAT(8, M, ~)) // 0 1 2 3 4 5 6 7 */

/* NEQ_PRIMITIVE(FOO, FOO) */
/* NEQ_PRIMITIVE(FOO, BAR) */

/* IS_COMPARABLE(FOO) */
/* IS_COMPARABLE(X) */

/* NEQ(FOO, BAR) */
/* NEQ(FOO, NOT_FOO) */
/* NEQ(FOO, FOO) */

/* IS_EMPTY() == 1 */
/* IS_EMPTY(X) == 0 */
/* IS_EMPTY(X, T) == 0 */

/* LENGTH() */
/* LENGTH(1) */
/* LENGTH(1, 2) */
/* LENGTH(1, 2, 3) */

/* FOREACH(ELEM, 1, 2, 3) */

/* FOREACH(ENUM_CASE, 1, 2, 3) */

int main(void) {
  cat_test();
  iif_test();
  not_test();
  if_test();
  when_test();
  defer_test();
  repeat_test();
  neq_primitive_test();
  is_comparable_test();
  neq_test();
  is_empty_test();
  length_test();
  enum_test();
  puts("Tests passed successfully!");
  return 0;
}
