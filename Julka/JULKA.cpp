#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<vector>
using namespace std;

vector<int> ToBigNum(char* strNum,vector<int> out)
{
	int strNumSize=strlen(strNum);
	for (int i = strNumSize-1; i >=0; i-=9)
	{
		char* numSegment=new char(9);
		for (int j = 0; j<9; j++)
		{
			numSegment[8-j]=strNum[i-j];
			if (i-j==0)
			{
				out.push_back(atoi(numSegment+8-j));
				break;
			}
			if (j==8)
			{
				out.push_back(atoi(numSegment));
				break;
			}
		}
	}
	return out;
}

vector<int> ClearLeadZeros(vector<int> bigNum)
{
	int bigNumSize=bigNum.size();
	for (int i = bigNumSize-1; i >=0; i--)
	{
		if (bigNum[i]==0)
		{
			if (bigNumSize>1)
			{
				bigNum.erase(bigNum.begin()+i);
				continue;
			}
			else
			{
				break;
			}
		}
		else
		{
			break;
		}
	}
	return bigNum;
}

vector<int> GetHalf(vector<int> bigNum,vector<int> out)
{
	bool mod2;
	int bigNumSize=bigNum.size();
	int carry=0;
	for (int i = bigNumSize-1; i >=0; i--)
	{
		mod2=bigNum[i]%2;
		out[i]=bigNum[i]/2+carry;
		if (mod2)
		{
			carry=500000000;
		}
		else
		{
			carry=0;
		}
	}

	out=ClearLeadZeros(out);
	return out;
}

vector<int> Take(vector<int> bigNum,vector<int> take,vector<int> out)
{
	int i;	
	int bigNumSize=bigNum.size();
	int takeSize=take.size();
	int carry=0;
	for (i = 0; i < takeSize; i++)
	{
		int dif=bigNum[i]-take[i]+carry;
		if (dif<0)
		{
			out[i]=1000000000+dif;
			carry=-1;
		}
		else
		{
			out[i]=dif;
			carry=0;
		}
	}
	if (carry<0)
	{
		for (i = takeSize; i < bigNumSize; i++)
		{
			int dif=bigNum[i]+carry;
			if (dif<0)
			{
				out[i]=1000000000+dif;
				carry=-1;
				continue;
			}
			else
			{
				out[i]=dif;
				break;
			}
		}
	}

	out=ClearLeadZeros(out);
	return out;
}

int main()
{
	int i,j;
	vector<vector<int> > output;
	char apples[102];
	char difference[102];
	for (i = 0; i < 10; i++)
	{
		scanf("%s",apples);
		scanf("%s",difference);
		vector<int> numApples;
		numApples=ToBigNum(apples,numApples);
		vector<int> numDifference;
		numDifference=ToBigNum(difference,numDifference);
		vector<int> nadia(numApples);
		nadia=GetHalf(numApples,nadia);
		nadia=Take(nadia,GetHalf(numDifference,numDifference),nadia);
		vector<int> klaudia(numApples);
		klaudia=Take(numApples,nadia,klaudia);
		output.push_back(klaudia);
		output.push_back(nadia);
	}
	
	int outputSize=output.size();
	for (i = 0; i < outputSize; i++)
	{
		int size=output[i].size();
		for (j = size-1; j >=0; j--)
		{
			int leadZero=100000000;
			while (leadZero>output[i][j] && leadZero>1 && j!=size-1)
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