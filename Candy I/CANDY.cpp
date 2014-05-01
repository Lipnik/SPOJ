#include<stdio.h>
#include<vector>
using namespace std;

int main()
{
	vector<int> output;
	int numOfPackets;
	scanf("%d",&numOfPackets);
	do
	{
		int numOfCandy;
		vector<int> packets;
		int sum=0;
		for (int i = 0; i < numOfPackets; i++)
		{
			scanf("%d",&numOfCandy);
			sum+=numOfCandy;
			packets.push_back(numOfCandy);
		}
		if (sum%numOfPackets!=0)
		{
			output.push_back(-1);
		}
		else
		{
			int numOfMoves=0;
			int avg=sum/numOfPackets;
			for (int j = 0; j < numOfPackets; j++)
			{
				if (packets[j]<avg)
				{
					numOfMoves+=(avg-packets[j]);
				}
			}
			output.push_back(numOfMoves);
		}
		scanf("%d",&numOfPackets);
	} while (numOfPackets!=-1);

	int outputSize=output.size();
	for (int i = 0; i < outputSize; i++)
	{
		printf("%d\n",output[i]);
	}
	return 0;
}