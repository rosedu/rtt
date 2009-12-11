int factorial(int n)
{
	int ret = 1;
	do {
		ret *= n;
	} while(--n);
	return ret;
}
