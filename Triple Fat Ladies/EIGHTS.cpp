#include<stdio.h>
#include<vector>
using namespace std;

int main()
{
	vector<long long> output;
	int N;
	scanf("%d",&N);
	for (int i = 0; i < N; i++)
	{
		long long k;
		scanf("%lld",&k);
		long long prefiks=(k-1)/4;
		int pattern=k%4;
		output.push_back(prefiks);
		switch (pattern)
		{
		case 0:
			output.push_back(942);
			break;
		case 1:
			output.push_back(192);
			break;
		case 2:
			output.push_back(442);
			break;
		case 3:
			output.push_back(692);
			break;
		default:
			break;
		}
	}

	int outputSize=output.size();
	for (int i = 0; i < outputSize; i+=2)
	{
		if (output[i]==0)
		{
			printf("%d\n",output[i+1]);
		}
		else
		{
			printf("%lld%d\n",output[i],output[i+1]);
		}
	}

	return 0;
}
