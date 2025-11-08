#ifndef __TEST_H__
#define __TEST_H__

#include "varargs.h"

#define TEST_DEF(TEST_NAME)			\
  void TEST_NAME##_test(void);

FOREACH(TEST_DEF, cat, iif, \
	not, if, when, defer, \
	repeat, neq_primitive, \
	is_comparable, neq, \
	is_empty, length, enum)

#endif
