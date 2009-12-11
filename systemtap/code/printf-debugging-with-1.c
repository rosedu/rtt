int factorial(int n)
{
	int ret;
	printf("f> enter n=%d ret=%d\n", n, ret);
	do {
		ret *= n;
	} while(n--);
	printf("f> exit  n=%d ret=%d\n", n, ret);
	return ret;
}
