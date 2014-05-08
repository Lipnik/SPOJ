#include<stdio.h>
#include<vector>
#include<map>
using namespace std;

map<int,long long> GoldToAmerican(int goldCoin,map<int,long long> memory,long long* out)
{
	if (goldCoin<12)
	{
		*out=goldCoin;
		return memory;
	}
	else
	{
		long long sum=0;
		for (int i = 4; i >= 2; i--)
		{
			int newGoldCoin=goldCoin/i;
			if (memory[newGoldCoin]==0)
			{
				memory=GoldToAmerican(newGoldCoin,memory,out);
				memory[newGoldCoin]=*out;

			}
			sum+=memory[newGoldCoin];
		}
		*out=sum;
		return memory;
	}
}

int main()
{
	int goldCoin;
	map<int,long long> memory;
	vector<long long> output;
	while (scanf("%d",&goldCoin)!=EOF)
	{
		long long american;
		memory=GoldToAmerican(goldCoin,memory,&american);
		output.push_back(american);
	}

	int outputSize=output.size();
	for (int i = 0; i < outputSize; i++)
	{
		printf("%lld\n",output[i]);
	}
	return 0;
}