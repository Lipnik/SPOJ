#include<stdio.h>
#include<vector>
using namespace std;

int main()
{
	int N;
	scanf("%d",&N);
	int x,y;
	vector<int> output;
	for (int i = 0; i < N; i++)
	{
		scanf("%d %d",&x,&y);
		if (x>=0 && y>=0 &&(x==y || x==y+2))
		{
			int number;
			if (x%2==0)
			{
				number=x+y;
			}
			else
			{
				number=x+y-1;
			}
			output.push_back(number);
		}
		else
		{
			output.push_back(-1);
		}
	}

	int outputSize=output.size();
	for (int i = 0; i < outputSize; i++)
	{
		if (output[i]>=0)
		{
			printf("%d\n",output[i]);
		}
		else
		{
			printf("No Number\n");
		}
	}
	return 0;
}
