#include<stdio.h>
#include<stdlib.h>
using namespace std;

long long Fibbonachi(int n,long long * memory)
{
	if (memory[n]==0)
	{
		memory[n]=Fibbonachi(n-2,memory)+Fibbonachi(n-1,memory);
	}
	return memory[n];
}

long long* NumOfDecodings (char* input,int* memSize,long long* memory,long long* count)
{
	*count=1;
	int n=1;
	int i=0;
	while (input[i]!=0)
	{
		if (input[i]==48)
		{
			i++;
			continue;
		}
		else if ((input[i]==49 || (input[i]==50 && input[i+1]<55)) && input[i+1]>48 && input[i+2]!=48)
		{
			n++;
			i++;
			continue;
		}
		else
		{
			if (n+1>*memSize)
			{
				memory=(long long*)realloc(memory,sizeof(long long)*(n+1));
				for (int j =*memSize ; j < n+1; j++)
				{
					memory[j]=0;
				}
				*memSize=n+1;
			}
			*count*=Fibbonachi(n,memory);
			n=1;
			i++;
			continue;
		}
	}
	return memory;
}

int main()
{
	int memSize=2;
	long long* fibMemory=(long long*)malloc(sizeof(long long)*memSize);
	fibMemory[0]=1;
	fibMemory[1]=1;
	long long* output=(long long*)malloc(sizeof(long long)*0);
	long long count;
	char input[5001];
	scanf("%s",input);
	int oIndex=0;
	while (input[0]!='0')
	{
		output=(long long*)realloc(output,sizeof(long long)*(++oIndex));
		fibMemory=NumOfDecodings(input,&memSize,fibMemory,&count);
		output[oIndex-1]=count;
		scanf("%s",input);
	} 
	int i;
	for (i = 0; i < oIndex; i++)
	{
		printf("%lld\n",output[i]);
	}
	return 0;
}