#include <stdio.h>

#define MY_STRING	"ana are mere"

#define MAX(a, b)	((a) > (b) ? (a) : (b))

int main(void)
{
#if 0
	printf("go go go!\n");
	aaaa
#endif
	printf("%s\n", MY_STRING);
	printf("max(5, 10) = %d\n", MAX(5, 10));

	return 0;
}
