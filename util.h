#ifndef __UTIL_H__
#define __UTIL_H__

#define CAT(A, ...) PRIMITIVE_CAT(A, __VA_ARGS__)
#define PRIMITIVE_CAT(A, ...) A ## __VA_ARGS__

#define CHECK_N(X, N, ...) N
#define CHECK(...) CHECK_N(__VA_ARGS__, 0)
#define PROBE(X) X, 1,

#define EMPTY_HELPER_ 0

#define HEAD(X, ...) X
#define TAIL(X, ...) __VA_ARGS__

#define IS_EMPTY(...) NOT(HEAD(EMPTY_HELPER_ ## __VA_ARGS__))

#endif
