#include<stdio.h>
#include <vector>
using namespace std;
int main()
{
	vector<int> output;
	int N;
	scanf("%d",&N);
	for (int i = 0; i < N; i++)
	{
		int a,b,lastDigit;
		scanf("%d %d",&a,&b);
		if (b==0)
		{
			output.push_back(1);
		}
		else
		{
			lastDigit=a;
			b%=4;
			if (b==0)
			{
				b=4;
			}
			for (int j = 1; j < b; j++)
			{
				lastDigit*=a;
			}
			lastDigit%=10;
			output.push_back(lastDigit);
		}
	}
	int outputSize=output.size();
	for (int i = 0; i < outputSize; i++)
	{
		printf("%d\n",output[i]);
	}
	return 0;
}