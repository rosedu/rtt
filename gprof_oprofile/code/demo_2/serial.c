#include <stdio.h>

int main()
{
	int start = 0, stop  = (1 << 30);
	int div2 = 0, div3 = 0;
	int i;

	for (i = start; i < stop; i++) {
		if (i % 2 == 0)
			div2 ++;
		if (i % 3 == 0)
			div3 ++;
	}

	printf("div2=%d, div3=%d\n", div2, div3);
	return 0;
}
