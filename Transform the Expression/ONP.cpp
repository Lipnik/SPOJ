#include<stdio.h>
#include<string.h>
#include<vector>
using namespace std;

int main()
{
	vector<vector<char> > output;
	int N;
	scanf("%d",&N);
	char expression[401];
	vector<char> operators;
	for (int i = 0; i < N; i++)
	{
		vector<char> RPN;	
		scanf("%s",expression);
		int expressionSize=strlen(expression);
		for (int j = 0; j < expressionSize; j++)
		{
			if (expression[j]=='(')
			{
				continue;
			}
			else if (expression[j]>=97 && expression[j]<=122)
			{
				RPN.push_back(expression[j]);
			}
			else if(expression[j]==')')
			{
				RPN.push_back(operators[operators.size()-1]);
				operators.pop_back();
			}
			else
			{
				operators.push_back(expression[j]);
			}
		}
		output.push_back(RPN);
	}
	int outputSize=output.size();
	for (int i = 0; i < outputSize; i++)
	{
		int RPNSize=output[i].size();
		for (int j = 0; j < RPNSize; j++)
		{
			printf("%c",output[i][j]);
		}
		printf("\n");
	}
	return 0;
}