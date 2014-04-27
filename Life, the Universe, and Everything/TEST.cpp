#include<iostream>
#include<vector>
using namespace std;

int main()
{
	int input;
	vector<int> output;
	while(scanf("%d",&input))
	{		
		if (input==42)
		{
			break;
		}
		else
		{
			output.push_back(input);
		}		
	}

	int outputSize=output.size();
	for (int i = 0; i < outputSize; i++)
	{
		printf("%d\n",output[i]);
	}
	return 0;
}