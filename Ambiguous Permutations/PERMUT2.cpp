#include<stdio.h>
#include<vector>
using namespace std;

int main()
{
	vector<bool> output;
	int N;
	scanf("%d",&N);
	do
	{
		int* perm=new int[N];
		int* invPerm=new int[N];
		int number;
		for (int i = 0; i < N; i++)
		{
			scanf("%d",&number);
			perm[i]=number;
			invPerm[number-1]=i+1;
		}
		bool ambigous=1;
		for (int i = 0; i < N; i++)
		{
			if (perm[i]!=invPerm[i])
			{
				ambigous=0;
				break;
			}
		}
		output.push_back(ambigous);
		scanf("%d",&N);
	} while (N>0);

	int outputSize=output.size();
	for (int i = 0; i < outputSize; i++)
	{
		if (output[i])
		{
			printf("ambiguous\n");
		}
		else
		{
			printf("not ambiguous\n");
		}
	}

	return 0;
}