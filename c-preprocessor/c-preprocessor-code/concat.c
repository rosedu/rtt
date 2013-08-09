#include <stdio.h>

#define SYSCALL(ret, name, ...)	ret __sys_ ## name(__VA_ARGS__)

SYSCALL(int, open, const char *path, int oflag, int mode)
{
	/* TODO */
	return 0;
}

SYSCALL(int, read, int fildes, void *buf, size_t nbytes)
{
	/* TODO */
	return 0;
}
