#include<stdio.h>

int main()
{
	long long n;
	scanf("%lld",&n);
	if ((n & (n-1))==0 || n==0)
	{
		printf("TAK");
	}
	else
	{
		printf("NIE");
	}
	return 0;
}