#include<iostream>
#include<vector>
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
			input/=5;
			numberOfZeros+=input;
		}
		output.push_back(numberOfZeros);
	}

	int outputSize=output.size();
	for (int i = 0; i < outputSize; i++)
	{
		printf("%d\n",output[i]);
	}
	return 0;
}