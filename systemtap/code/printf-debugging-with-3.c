int factorial(int n)
{
	int ret = 1;
	printf("f> enter n=%d ret=%d\n", n, ret);
	do {
		ret *= n;
		printf("n=%d ret=%d\n", n, ret);
	} while(n--);
	printf("f> exit  n=%d ret=%d\n", n, ret);
	return ret;
}
