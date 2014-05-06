#include<stdio.h>
#include<vector>
using namespace std;

int main()
{
	int N;
	char yes[4]={'Y','E','S',0};
	char no[3]={'N','O',0};
	vector<char*> output;
	scanf("%d",&N);
	for (int i = 0; i < N; i++)
	{
		unsigned long long sum=0;
		int children;
		scanf("%d",&children);
		for (int j = 0; j < children; j++)
		{
			unsigned long long candy;
			scanf("%llu",&candy);
			sum=(sum+candy)%children;
		}
		if (sum==0)
		{
			output.push_back(yes);
		}
		else
		{
			output.push_back(no);
		}
	}

	int outputSize=output.size();
	for (int i = 0; i < outputSize; i++)
	{
		printf("%s\n",output[i]);
	}
	return 0;
}