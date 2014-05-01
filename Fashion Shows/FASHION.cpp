#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;

int main()
{
	vector<int> output;
	int N;
	scanf("%d",&N);
	for (int i = 0; i < N; i++)
	{
		int numOfCandidates;
		scanf("%d",&numOfCandidates);
		int men;
		int women;
		vector<int> numMen;
		vector<int> numWomen;
		for (int j = 0; j < numOfCandidates; j++)
		{
			scanf("%d",&men);
			numMen.push_back(men);
		}
		for (int j = 0; j < numOfCandidates; j++)
		{
			scanf("%d",&women);
			numWomen.push_back(women);
		}
		sort(numMen.begin(),numMen.end());
		sort(numWomen.begin(),numWomen.end());
		int sum=0;
		int size=numMen.size();
		for (int j = 0; j < size; j++)
		{
			sum+=numMen[j]*numWomen[j];
		}
		output.push_back(sum);
	}

	int outputSize=output.size();
	for (int i = 0; i < outputSize; i++)
	{
		printf("%d\n",output[i]);
	}
	return 0;
}
