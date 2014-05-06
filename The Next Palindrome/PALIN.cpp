#include<stdio.h>
#include<string.h>
using namespace std;

int main()
{
	int N;
	scanf("%d",&N);
	char** output=new char*[N];
	int outputSize=0;
	for (int i = 0; i < N; i++)
	{
		int inputSize;
		char* input=new char[1000002];
		scanf("%s",input);
		inputSize=strlen(input);
		int pos1,pos2;
		int range=inputSize/2;
		pos1=range-1;
		pos2=inputSize-range;
		bool simple=0;
		for (int j = 0; j < range; j++)
		{
			if (input[pos1-j]>input[pos2+j])
			{
				simple=1;
				break;
			}
			else if(input[pos1-j]<input[pos2+j])
			{
				break;
			}
			else
			{
				continue;
			}
		}
		if (simple)
		{
			for (int j = 0; j < range; j++)
			{
				input[pos2+j]=input[pos1-j];
			}
		}
		else
		{
			if (inputSize%2!=0)
			{
				pos2=++pos1;
				range++;
			}
			int carry=1;
			for (int j = 0; j < range; j++)
			{
				if (carry==1)
				{
					input[pos1-j]+=carry;
					if (input[pos1-j]>57)
					{
						input[pos1-j]='0';
						carry=1;
					}
					else
					{
						carry=0;
					}
				}
				input[pos2+j]=input[pos1-j];
			}
			if (carry==1)
			{
				input[0]='1';
				input[inputSize]='1';
				input[inputSize+1]=0;
			}
		}
		output[outputSize++]=input;
	}

	for (int i = 0; i < outputSize; i++)
	{
		printf("%s\n",output[i]);
	}
	return 0;
}