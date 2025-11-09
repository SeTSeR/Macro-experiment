#include "arith.h"
#include "control.h"
#include "util.h"

#ifndef __COMPARE_H__
#define __COMPARE_H__

#define IS_PAREN(X) CHECK(IS_PAREN_PROBE X)
#define IS_PAREN_PROBE() PROBE(K)

#define NEQ_PRIMITIVE(L, R) IS_PAREN(					\
									NEQ_ ## L (NEQ_ ## R) (()))

#define IS_COMPARABLE(X) IS_PAREN (CAT(NEQ_, X) (()))

#define NEQ(X, Y)					\
  IIF (BITAND(IS_COMPARABLE(X))(IS_COMPARABLE(Y)))	\
    (NEQ_PRIMITIVE, 1 NONE)(X, Y)

#define EQ(X, Y) INV(NEQ(X, Y))

#endif
