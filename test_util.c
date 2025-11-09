#include "util.h"

/* CAT test */
#define AB 3

#if (CAT(AB) != AB)
#error "Macro CAT(A, B) was expanded incorrectly"
#endif

#undef AB

#define X 1
#define B1 4

#if (CAT(B, X) != B1)
#error "Macro CAT(B, X) was expanded incorrectly"
#endif

#undef B1
#undef X
/* CAT test */
