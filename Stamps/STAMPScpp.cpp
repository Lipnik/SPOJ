#include<stdio.h>
#include<algorithm>
#include<vector>
using namespace std;

int main()
{
	vector<int> output;
	int N;
	scanf("%d",&N);
	for (int i = 0; i < N; i++)
	{
		vector<int> forBorrow;
		int neededStamps, friends,friendStamps;
		scanf("%d %d",&neededStamps, &friends);
		for (int j = 0; j < friends; j++)
		{
			scanf("%d",&friendStamps);
			forBorrow.push_back(friendStamps);
		}
		sort(forBorrow.begin(),forBorrow.end());
		int forBorrowSize=forBorrow.size();
		int j;
		for (j = 1; j <= forBorrowSize; j++)
		{
			neededStamps-=forBorrow[forBorrowSize-j];
			if (neededStamps<=0)
			{
				break;
			}
		}
		if (j!=forBorrowSize+1)
		{
			output.push_back(j);
		}
		else
		{
			output.push_back(-1);
		}
	}

	int outputSize=output.size();
	for (int i = 0; i < outputSize; i++)
	{
		if (output[i]!=-1)
		{
			printf("Scenario #%d:\n%d\n\n",i+1,output[i]);
		}
		else
		{
			printf("Scenario #%d:\nimpossible\n\n",i+1);
		}
	}

	return 0;
}