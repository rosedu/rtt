#include "sample.h"

#define TEST_NUM   25
#define MAX(a, b)  ((a) > (b) ? (a) : (b))

int main(void)
{
	test_fun(TEST_NUM);
	test_max(MAX(5, 10));

	return 0;
}
