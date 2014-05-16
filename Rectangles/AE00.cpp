#include<stdio.h>

int main()
{
	int N;
	scanf("%d",&N);
	int rectangles=0;
	int i;
	for (i = 1; i*i <= N; i++)
	{
		rectangles+=N/i;
	}
	rectangles+=((-(--i)*i+i)/2);
	printf("%d",rectangles);
	return 0;
}