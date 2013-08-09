#include <stdio.h>

#define DBG(val, fmt)	\
	fprintf(stderr, #val " = " fmt "\n", val)

int main(void)
{
	int a = 42;
	char *s = "hax0r";

	DBG(a, "%d");
	DBG(s, "%s");

	return 0;
}
