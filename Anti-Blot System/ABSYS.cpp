#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<vector>
using namespace std;

int main()
{
	vector<int> output;
	int N;
	char machula[8]={'m','a','c','h','u','l','a',0};
	int numInputs[3];
	char* inputs[3];
	for (int i = 0; i < 3; i++)
	{
		inputs[i]=new char[17];
	}
	scanf("%d",&N);
	for (int i = 0; i < N; i++)
	{
		scanf("%s + %s = %s",inputs[0],inputs[1],inputs[2]);

		for (int j = 0; j < 3; j++)
		{
			if (strstr(inputs[j],machula)!=NULL)
			{
				numInputs[j]=-1;
			}
			else
			{
				numInputs[j]=atoi(inputs[j]);
			}
		}

		if (numInputs[0]==-1)
		{
			numInputs[0]=numInputs[2]-numInputs[1];
		}
		else if (numInputs[1]==-1)
		{
			numInputs[1]=numInputs[2]-numInputs[0];
		}
		else
		{
			numInputs[2]=numInputs[0]+numInputs[1];
		}

		output.push_back(numInputs[0]);
		output.push_back(numInputs[1]);
		output.push_back(numInputs[2]);
	}

	int outputSize=output.size();
	for (int i = 0; i < outputSize; i+=3)
	{
		printf("%d + %d = %d\n",output[i],output[i+1],output[i+2]);
	}

	return 0;
}