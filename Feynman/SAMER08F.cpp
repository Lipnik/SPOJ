#include<stdio.h>
#include<vector>
#include<math.h>
using namespace std;

int main()
{
	vector<int> output;
	int size;
	scanf("%d",&size);
	do
	{
		int numberOfSquares;
		numberOfSquares=size*(size+1)*(size+1)-ceil(2*size*size*size/3.+3*size*size/2.+5*size/6.);
		output.push_back(numberOfSquares);
		scanf("%d",&size);
	}while(size>0);

	int outputSize=output.size();
	for (int i = 0; i < outputSize; i++)
	{
		printf("%d\n",output[i]);
	}
	return 0;
}