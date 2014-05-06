#include<stdio.h>

int main()
{
	int N;
	scanf("%d",&N);
	int rectangles=0;
	for (int i = 1; i*i <= N; i++)
	{
		int maxj=N/i;
		for (int j = i; j <= maxj; j++)
		{
			rectangles++;
		}
	}
	printf("%d",rectangles);
	return 0;
}