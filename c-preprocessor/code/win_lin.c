#include <stdio.h>

int main (void)
{
#if defined (__linux__)
	printf ("This is Linux.\n");
#elif defined (__win32__) 
	printf ("This is Win32.\n");
#else
	printf ("This is Sparta.\n");
#endif

	return 0;
}
