#include<stdio.h>
#include<vector>
using namespace std;

int main()
{
	vector<int> output;
	int N;
	scanf("%d",&N);
	do
	{
		int numberOfSquares=0;
		for (int i = 1; i <= N; i++)
		{
			numberOfSquares+=((N-i+1)*(N-i+1));
		}
		output.push_back(numberOfSquares);
		scanf("%d",&N);
	}while(N>0);

	int outputSize=output.size();
	for (int i = 0; i < outputSize; i++)
	{
		printf("%d\n",output[i]);
	}
	return 0;
}