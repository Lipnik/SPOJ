#include<stdio.h>
#include<vector>
using namespace std;

int main()
{
	int N;
	long long f3, l3, sum;
	scanf("%d",&N);
	long long* output = new long long[N * 3];
	int oIndex = 0;
	for (int i = 0; i < N; i++)
	{
		scanf("%lld %lld %lld", &f3, &l3, &sum);
		long long n = (2 * sum) / (f3 + l3);
		long long d = (l3 - f3) / (n - 5);
		long long first = f3 - 2 * d;
		output[oIndex++]=first;
		output[oIndex++]=d;
		output[oIndex++]=n;
	}

	for (int i = 0; i < oIndex; i+=3)
	{
		printf("%lld\n",output[i+2]);
		for (long long j = 0; j < output[i+2]; j++)
		{
			if (j!=output[i+2]-1)
			{
				printf("%lld ", output[i] + j*output[i + 1]);
			}
			else
			{
				printf("%lld\n", output[i] + j*output[i + 1]);
			}
		}
	}

	return 0;
}