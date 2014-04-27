#include<iostream>
#include<vector>
#include<math.h>
using namespace std;

int ReverseNumber(int number)
{
	bool notLeadZero=false;
	vector<int> digits;
	while (number>0)
	{
		int tmp=number%10;
		if (tmp!=0 || notLeadZero)
		{
			notLeadZero=true;
			digits.push_back(tmp);
		}
		number=number/10;
	}
	int rNumber=0;
	int numberOfDigits=digits.size();
	for (int i = 0; i < numberOfDigits; i++)
	{
		rNumber=rNumber+digits[numberOfDigits-1-i]*pow(10,i);
	}
	return rNumber;
}

int main()
{
	int N;
	vector<int> output;
	scanf("%d",&N);
	for (int i = 0; i < N; i++)
	{
		int number1,number2,sum;
		scanf("%d %d",&number1,&number2);
		number1=ReverseNumber(number1);
		number2=ReverseNumber(number2);
		sum=number1+number2;
		sum=ReverseNumber(sum);
		output.push_back(sum);
	}
	int outputSize=output.size();
	for (int i = 0; i < outputSize; i++)
	{
		printf("%d\n",output[i]);
	}

	return 0;
}

