#include <stdio.h>

int main()
{
	char a, sir[256];
	int i = 0;
	for (a = 0; a < 256; a++)
		sir[i++] = a;
	printf("Result: %s\n", sir);
	return 0;
}
