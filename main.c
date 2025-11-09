#include "test.h"

#include <stdio.h>

int main(void) {
  defer_test();
  repeat_test();
  enum_test();
  puts("Tests passed successfully!");
  return 0;
}
