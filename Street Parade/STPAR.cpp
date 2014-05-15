#include<stdio.h>
#include<vector>
#include<stack>
using namespace std;

int main()
{
	vector<bool> output;
	int paradeSize;
	scanf("%d",&paradeSize);
	while (paradeSize>0)
	{
		int mobileNum;
		vector<int> parade;
		for (int i = 0; i < paradeSize; i++)
		{
			scanf("%d",&mobileNum);
			parade.push_back(mobileNum);
		}
		stack<int> sideStreet;
		sideStreet.push(0);
		int next=1;
		for (int i = 0; i <=paradeSize; i++)
		{
			if (i<paradeSize && parade[i]==next)
			{
				next++;
				continue;
			}
			else if(sideStreet.top()==next)
			{
				sideStreet.pop();
				next++;
				i--;
				continue;
			}
			else
			{
				if (i<paradeSize)
				{
					sideStreet.push(parade[i]);
				}
				continue;
			}
		}
		if (sideStreet.top()==0)
		{
			output.push_back(1);
		}
		else
		{
			output.push_back(0);
		}
		scanf("%d",&paradeSize);
	}

	int ouputSize=output.size();
	for (int i = 0; i < ouputSize; i++)
	{
		if (output[i])
		{
			printf("yes\n");
		}
		else
		{
			printf("no\n");
		}
	}

	return 0;
}