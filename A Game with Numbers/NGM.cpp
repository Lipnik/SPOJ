#include<stdio.h>
using namespace std;

int main()
{
	long long start;
	scanf("%lld",&start);
	int lastDigit = start % 10;
	if (lastDigit)
	{
		printf("1\n%d\n", lastDigit);
	}
	else
	{
		printf("2\n");
	}
	return 0;
}