#include<iostream>
#include<vector>
#include<math.h>
using namespace std;

int main()
{
	int N;
	int input;
	vector<int> output;
	scanf("%d",&N);
	for (int i = 0; i < N; i++)
	{
		scanf("%d",&input);
		int numberOfZeros=0;
		while (input>=5)
		{
			input=input/5;
			numberOfZeros=numberOfZeros+input;
		}
		output.push_back(numberOfZeros);
	}

	for (int i = 0; i < output.size(); i++)
	{
		printf("%d\n",output[i]);
	}
	return 0;
}