#include<iostream>
#include<vector>
using namespace std;

int main()
{
	int input;
	vector<int> outputs;
	while(scanf("%d",&input))
	{		
		if (input==42)
		{
			break;
		}
		else
		{
			outputs.push_back(input);
		}		
	}

	for (int i = 0; i < outputs.size(); i++)
	{
		printf("%d\n",outputs[i]);
	}
	return 0;
}