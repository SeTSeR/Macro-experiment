#include "varargs.h"

/* IS_EMPTY test begin */

#if INV(IS_EMPTY())
#error "IS_EMPTY() was expanded incorrectly"
#endif

#if IS_EMPTY(X)
#error "IS_EMPTY(X) was expanded incorrectly"
#endif

#if IS_EMPTY(X, T)
#error "IS_EMPTY(X, T) was expanded incorrectly"
#endif

/* IS_EMPTY test end */

/* LENGTH test begin */

#if LENGTH() != 0
#error "LENGTH() was expanded incorrectly"
#endif

#if LENGTH(1) != 1
#error "LENGTH(1) was expanded incorrectly"
#endif

#if LENGTH(1, 2) != 2
#error "LENGTH(1, 2) was expanded incorrectly"
#endif

#if LENGTH(1, 2, 3) != 3
#error "LENGTH(1, 2, 3) was expanded incorrectly"
#endif

/* LENGTH test end */
