#include <stdio.h>

#define Q <
#define M 42
#define ADD(x) (M+x)

int main()
{
#define N 28
	printf("Salut.\n");
#undef N
	printf("Nothing exists here.\n");
#define N 1729
	printf("Bye.\n");
	return 0;
}
