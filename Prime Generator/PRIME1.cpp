#include<stdio.h>

bool IsPrime (int candidate,int* checkPrimes,int size)
{
	for (int i = 0; i < size; i++)
	{		
		if (checkPrimes[i]*checkPrimes[i]>candidate)
		{
			break;
		}	
		if (candidate%checkPrimes[i]==0)
		{
			return 0;
		}
	}
	return 1;
}

int main()
{
	const int sqrtLimit=31623;//ceil(sqrt(1000000000))
	const int maxPrimes=9593;//number of primes from 1 to 100001
	const int checkPrimesSize=3401;
	int checkPrimes[checkPrimesSize];
	int pIndex=0;
	int i,j;
	int oIndex=0;
	int N;

	//sieve
	bool prime[sqrtLimit];
	for (i = 0; i < sqrtLimit; i++)
	{
		prime[i]=1;
	}
	prime[0]=0;
	prime[1]=0;
	for (i = 2; i < sqrtLimit; i++)
	{
		if (prime[i])
		{
			checkPrimes[pIndex++]=i;
			for (int j = i*i; j < sqrtLimit; j+=i)
			{
				prime[j]=0;
			}
		}
	}

	scanf("%d",&N);
	int** output= new int*[N];
	for (i = 0; i < N; i++)
	{
		int* primes=new int[maxPrimes];
		pIndex=1;
		int min,max;
		scanf("%d %d",&min,&max);
		if (max<=sqrtLimit)
		{
			for (j = 0; j < checkPrimesSize; j++)
			{
				if (checkPrimes[j]>=min &&checkPrimes[j]<=max)
				{
					primes[pIndex++]=checkPrimes[j];
				}
			}
		}
		else
		{
			if (min<sqrtLimit)
			{
				for (j = 0; j < checkPrimesSize; j++)
				{
					if (checkPrimes[j]>=min)
					{
						primes[pIndex++]=checkPrimes[j];
					}
				}
				min=sqrtLimit+3;
			}
			else
			{
				int mod6=min%6;
				if (mod6==1)
				{
					if (IsPrime(min,checkPrimes,checkPrimesSize))
					{
						primes[pIndex++]=min;
					}
					min+=5;
				}
				else if (mod6==0)
				{
					if (min+1<=max)
					{
						if (IsPrime(min+1,checkPrimes,checkPrimesSize))
						{
							primes[pIndex++]=min+1;
						}
					}
					min+=6;
				}
				else
				{
					min+=(6-mod6);
				}
			}
			for (j = min; j-1<= max; j+=6)
			{
				if (IsPrime(j-1,checkPrimes,checkPrimesSize))
				{
					primes[pIndex++]=j-1;
				}
				if (j+1<=max)
				{
					if (IsPrime(j+1,checkPrimes,checkPrimesSize))
					{
						primes[pIndex++]=j+1;
					}
				}
			}
		}
		primes[0]=pIndex;
		output[oIndex++]=primes;
	}

	for (i = 0; i < oIndex; i++)
	{
		for (int j = 1; j < output[i][0]; j++)
		{
			printf("%d\n",output[i][j]);
		}
		printf("\n");
	}

	return 0;
}