unsigned long long factorialCheck(unsigned long long n)
{
	if ((n == 0) || (n == 1))
		return 1;
	else
		return n * factorialCheck(n - 1);
}