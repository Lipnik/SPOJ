#include<stdio.h>
#include<vector>
using namespace std;

int main()
{
	vector<int> output;
	int N;
	scanf("%d",&N);
	for (int i = 0; i < N; i++)
	{
		int term;
		scanf("%d",&term);
		int diagonal=0;
		int maxTerm;
		do
		{
			diagonal++;
			maxTerm=diagonal*(diagonal+1)/2;
		} while (maxTerm<term);
		int top=1;
		int bottom=diagonal;
		int diff;
		if (diagonal%2==0)
		{
			diff=term-maxTerm+diagonal-1;
		}
		else
		{
			diff=maxTerm-term;
		}
		top+=diff;
		bottom-=diff;
		output.push_back(term);
		output.push_back(top);
		output.push_back(bottom);
	}

	int outputSize=output.size();
	for (int i = 0; i < outputSize; i+=3)
	{
		printf("TERM %d IS %d/%d\n",output[i],output[i+1],output[i+2]);
	}

	return 0;
}