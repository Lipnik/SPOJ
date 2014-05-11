#include<stdio.h>
int main()
{	
	int N;
	scanf("%d",&N);
	long long* output=new long long[N];
	long long count;
	int i,j,k;
	long long x,y;
	for (k = 0; k < N; k++)
	{	
		scanf("%lld",&x);
		y=x/2;
		count=(3*x*x*y-6*x*y*y+3*x*y+4*y*y*y+x*x*x+3*x*x-3*y*y+2*x-y)/6;
		output[k]=count;
	}
	for (i = 0; i < N; i++)
		printf("%lld\n",output[i]);	
	return 0;
}