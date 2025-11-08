#ifndef __ENUM_H__
#define __ENUM_H__

#include "varargs.h"

#define ELEM(X) X,

#define CASE(X)					\
  case X:					\
  return #X;

#define ENUM(NAME, ...)				\
  typedef enum {				\
    FOREACH(ELEM, __VA_ARGS__)			\
  } NAME

#define ENUM_TO_STR(NAME, ...)			\
  const char *NAME_##to_str(NAME value) {	\
    switch (value) {				\
      FOREACH(CASE, __VA_ARGS__)		\
	}					\
  }

#define SERIALIZED_ENUM(...)			\
  ENUM(__VA_ARGS__);				\
  ENUM_TO_STR(__VA_ARGS__)

#endif
