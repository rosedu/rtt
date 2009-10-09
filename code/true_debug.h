#ifndef DEBUG_H_
#define DEBUG_H_	1

#if defined DEBUG__
  #define Dprintf(format, ...) \
	fprintf(stderr, "[%s]:%s:%d: " format, __FILE__, \
		__func__, __LINE__, ##__VA_ARGS__)
#else
  #define Dprintf(format, ...)  do { } while(0)
#endif

#endif
