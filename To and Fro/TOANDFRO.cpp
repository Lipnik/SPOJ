#include<stdio.h>
#include<vector>
#include<string.h>
using namespace std;

int main()
{
	vector<vector<char> > output;
	int columns;
	char inMessage[201];
	scanf("%d",&columns);
	do
	{
		scanf("%s",inMessage);
		int inMessageSize=strlen(inMessage);
		vector<char> outMessage;	
		int reverseOffset=columns-1;
		for (int i = 0; i < columns; i++)
		{
			int leftRight=1;
			for (int j = i; j < inMessageSize; j+=columns)
			{
				if (leftRight==1)
				{
					outMessage.push_back(inMessage[j]);
				}
				else
				{
					outMessage.push_back(inMessage[j+reverseOffset]);
				}
				leftRight=-leftRight;
			}
			reverseOffset-=2;
		}
		output.push_back(outMessage);
		scanf("%d",&columns);
	} while (columns>0);

	int outputSize=output.size();
	for (int i = 0; i < outputSize; i++)
	{
		int messageSize=output[i].size();
		for (int j = 0; j < messageSize; j++)
		{
			printf("%c",output[i][j]);
		}
		printf("\n");
	}

	return 0;
}