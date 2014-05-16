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
		int numberOfSquares=(2*N*N*N+3*N*N+N)/6;
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