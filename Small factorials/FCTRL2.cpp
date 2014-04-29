#include<iostream>
#include<vector>
using namespace std;

int main()
{
	int N;
	scanf("%d",&N);
	vector<vector<int> > output;
	for (int i = 0; i < N; i++)
	{
		int input;
		scanf("%d",&input);
		vector<int> fact;
		fact.push_back(1);
		while (input>1)
		{
			int carry=0;
			int factSize=fact.size();
			for (int i = 0; i < factSize; i++)
			{
				fact[i]=fact[i]*input+carry;
				carry=fact[i]/10000000;
				fact[i]%=10000000;
			}
			if (carry!=0)
			{
				fact.push_back(carry);
			}
			input--;
		}
		output.push_back(fact);
	}

	int outputSize=output.size();
	for (int i = 0; i < outputSize; i++)
	{
		int factSize=output[i].size();
		for (int j = factSize-1; j >=0; j--)
		{
			int leadZero=1000000;
			while (leadZero>output[i][j] && leadZero>1 && j!=factSize-1)
			{
				printf("0");
				leadZero=leadZero/10;
			}
			printf("%d",output[i][j]);
		}
		printf("\n");
	}
	return 0;
}