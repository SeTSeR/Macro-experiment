#include "util.h"

#ifndef __ARITH_H__
#define __ARITH_H__

#define INC(X) PRIMITIVE_CAT(INC_, X)
#define INC_0 1
#define INC_1 2
#define INC_2 3
#define INC_3 4
#define INC_4 5
#define INC_5 6
#define INC_6 7
#define INC_7 8
#define INC_8 9
#define INC_9 10
#define INC_10 10

#define DEC(X) PRIMITIVE_CAT(DEC_, X)
#define DEC_0 0
#define DEC_1 0
#define DEC_2 1
#define DEC_3 2
#define DEC_4 3
#define DEC_5 4
#define DEC_6 5
#define DEC_7 6
#define DEC_8 7
#define DEC_9 8
#define DEC_10 9

#define BITAND(X) PRIMITIVE_CAT(BITAND_, X)
#define BITAND_0(X) 0
#define BITAND_1(X) X

#define INV(X) PRIMITIVE_CAT(INV_, X)
#define INV_0 1
#define INV_1 0

#endif
