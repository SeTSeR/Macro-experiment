#ifndef __EVAL_H__
#define __EVAL_H__

#define EVAL(...)  EVAL1(EVAL1(EVAL1(EVAL1(__VA_ARGS__))))
#define EVAL1(...) EVAL2(EVAL2(EVAL2(EVAL2(__VA_ARGS__))))
#define EVAL2(...) EVAL3(EVAL3(EVAL3(EVAL3(__VA_ARGS__))))
#define EVAL3(...) EVAL4(EVAL4(EVAL4(EVAL4(__VA_ARGS__))))
#define EVAL4(...) EVAL5(EVAL5(EVAL5(EVAL5(__VA_ARGS__))))
#define EVAL5(...) __VA_ARGS__

#endif
