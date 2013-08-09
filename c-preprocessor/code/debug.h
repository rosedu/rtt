#ifndef DEBUG_H_
#define DEBUG_H_	1

#include <stdio.h>

#define DEBUG(fmt, ...)	fprintf(stderr, fmt, ##__VA_ARGS__)

#endif
