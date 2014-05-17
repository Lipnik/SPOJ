#include<stdio.h>
#include<string.h>
#include<vector>
using namespace std;

void Take(char* a, char* b, char* out)
{
	int aSize=strlen(a);
	int bSize=strlen(b);
	int offset=aSize-bSize;
	int carry=0;
	for (int i =bSize-1 ; i >=0; i--)
	{
		int digit=a[i+offset]-b[i]+carry;
		if (digit<0)
		{
			digit+=10;
			carry=-1;
		}
		else
		{
			carry=0;
		}
		out[i+offset]=digit+48;
	}
	for (int i = offset-1; i >= 0; i--)
	{
		int digit=a[i]+carry-48;
		if (digit<0)
		{
			digit+=10;
			carry=-1;
		}
		else
		{
			carry=0;
		}
		out[i]=digit+48;
		continue;
	}
	out[aSize]=0;
}

int main()
{
	vector<char*> output;
	int i,j;
	char apples[102];
	char difference[102];
	for (i = 0; i < 10; i++)
	{
		scanf("%s",apples);
		scanf("%s",difference);
		char* nadia=new char[102];
		Take(apples,difference,nadia);
		int nadiaSize=strlen(nadia);
		int carry=0;
		for (j = 0; j < nadiaSize; j++)
		{
			int digit=nadia[j]-48;
			bool mod2=digit%2;
			digit=digit/2+carry;
			if (mod2)
			{
				carry=5;
			}
			else
			{
				carry=0;
			}
			nadia[j]=digit+48;
		}
		char* klaudia=new char[102];
		Take(apples,nadia,klaudia);
		for (j = 0; klaudia[j]==48 ; j++)
		{
			if (klaudia[j+1]==0)
			{
				break;
			}
		}
		klaudia+=j;
		output.push_back(klaudia);
		for (j = 0; nadia[j]==48 ; j++)
		{
			if (nadia[j+1]==0)
			{
				break;
			}
		}
		nadia+=j;
		output.push_back(nadia);
	}

	int outputSize=output.size();
	for (i = 0; i < outputSize; i+=2)
	{
		printf("%s\n%s\n",output[i],output[i+1]);
	}
	return 0;
}