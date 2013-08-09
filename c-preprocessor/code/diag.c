#include <stdio.h>

int main(void)
{
#ifdef __x86_64__
#warning "why?"
#endif

#if defined __linux__ && ! defined DEBUG__
#error "DEBUG__ macro must be defined on Linux"
#endif

	printf("Hello, World!\n");

	return 0;
}
