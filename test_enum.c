#include "enum.h"

#include <assert.h>
#include <stdio.h>
#include <string.h>

SERIALIZED_ENUM(enum1, v1, v2, v3)

void enum_test(void) {
#define BUF_SIZE 265
  char buf[BUF_SIZE];
  enum1 x = v1;
  enum1 y = v2;
  enum1 z = v3;
  snprintf(buf, BUF_SIZE, "%s %s %s", enum1_to_str(x), enum1_to_str(y),
           enum1_to_str(z));
  assert(strcmp("v1 v2 v3", buf) == 0 &&
         "SERIALIZED_ENUM(enum1, v1, v2, v3) was expanded incorrectly");
#undef BUF_SIZE
  puts("enum_test passed!");
}
