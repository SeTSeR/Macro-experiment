#include "control.h"
#include "eval.h"

#define EMPTY_HELPER_ 0

#define HEAD(X, ...) X
#define TAIL(X, ...) __VA_ARGS__

#define IS_EMPTY(...) NOT(HEAD(EMPTY_HELPER_ ## __VA_ARGS__))
#ifndef __VARARGS_H__
#define __VARARGS_H__

#define LENGTH(...) EVAL(LENGTH_HELPER(0, __VA_ARGS__))
#define LENGTH_HELPER(COUNT, ...)					\
  IF (IS_EMPTY(__VA_ARGS__)) (						\
			      COUNT, DOUBLE_DEFER(LENGTH_AGAIN)()(INC(COUNT), TAIL(__VA_ARGS__)) \
			      )
#define LENGTH_AGAIN() LENGTH_HELPER

#define FOREACH(...) EVAL(FOREACH_HELPER(__VA_ARGS__))
#define FOREACH_HELPER(F, ...)						\
  WHEN (INV(IS_EMPTY(__VA_ARGS__))) (					\
				      DOUBLE_DEFER(F)(HEAD(__VA_ARGS__)) \
				      DOUBLE_DEFER(FOREACH_AGAIN)()(F, TAIL(__VA_ARGS__)) \
				      )
#define FOREACH_AGAIN() FOREACH_HELPER

#endif
