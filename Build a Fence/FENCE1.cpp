#include<stdio.h>
#include<vector>
using namespace std;

int main()
{
	const double pi=3.141592654;
	vector<double> output;
	int L;
	scanf("%d",&L);
	while (L!=0)
	{
		output.push_back((L*L)/(2*pi));
		scanf("%d",&L);
	}

	int outputSize=output.size();
	for (int i = 0; i < outputSize; i++)
	{
		printf("%.2f\n",output[i]);
	}

	return 0;
}