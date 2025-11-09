#include "compare.h"

#define NEQ_FOO(X) X
#define NEQ_BAR(X) X

/* NEQ_PRIMITIVE test begin */

#if NEQ_PRIMITIVE(FOO, FOO)
#error "NEQ_PRIMITIVE(FOO, FOO) was expanded incorrectly"
#endif

#if INV(NEQ_PRIMITIVE(FOO, BAR))
#error "NEQ_PRIMITIVE(FOO, BAR) was expanded incorrectly"
#endif

/* NEQ_PRIMITIVE test end */

/* IS_COMPARABLE test begin */

#if INV(IS_COMPARABLE(FOO))
#error "IS_COMPARABLE(FOO) was expanded incorrectly"
#endif

#if IS_COMPARABLE(X)
#error "IS_COMPARABLE(X) was expanded incorrectly"
#endif

/* IS_COMPARABLE test end */

/* NEQ test begin */

#if INV(NEQ(FOO, BAR))
#error "NEQ(FOO, BAR) was expanded incorrectly"
#endif

#if INV(NEQ(FOO, NOT_FOO))
#error "NEQ(FOO, NOT_FOO) was expanded incorrectly"
#endif

#if NEQ(FOO, FOO)
#error "NEQ(FOO, FOO) was expanded incorrectly"
#endif

/* NEQ test end */
