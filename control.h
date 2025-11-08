#ifndef __CONTROL_H__
#define __CONTROL_H__

#include "arith.h"
#include "util.h"

#define IIF(COND) PRIMITIVE_CAT(IIF_, COND)
#define IIF_0(S_TRUE, ...) __VA_ARGS__
#define IIF_1(S_TRUE, ...) S_TRUE

#define NOT(X) CHECK(PRIMITIVE_CAT(NOT_, X))
#define NOT_0 PROBE(1)

#define IF(COND) IIF(INV(NOT(COND)))

#define WHEN(COND) IF(COND)(EXPAND, NONE)
#define EXPAND(...) __VA_ARGS__
#define NONE(...)

#define EMPTY()
#define DEFER(X) X EMPTY()
#define DOUBLE_DEFER(...) __VA_ARGS__ DEFER(EMPTY)()

#define REPEAT(COUNT, F, ...)						\
  WHEN(COUNT)								\
    (									\
								DOUBLE_DEFER(REPEAT_NEXT)()(DEC(COUNT), F, __VA_ARGS__)	\
								DOUBLE_DEFER(F)(DEC(COUNT), __VA_ARGS__) \
								)
#define REPEAT_NEXT() REPEAT

#define WHILE(COND, F, ...)						\
  IF(COND(__VA_ARGS__))(						\
									DOUBLE_DEFER(WHILE_NEXT)()(COND, F, F(__VA_ARGS__)), \
									__VA_ARGS__)
#define WHILE_NEXT() WHILE

#endif
