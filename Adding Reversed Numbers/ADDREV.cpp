#include<iostream>
#include<vector>
using namespace std;

int ReverseNumber(int number)
{
	bool LeadZero=true;
	vector<int> digits;
	while (number>0)
	{
		int tmp=number%10;
		number/=10;
		if (LeadZero)
		{
			if (tmp!=0)
			{
				LeadZero=false;
			}
			else
			{
				continue;
			}		
		}
		digits.push_back(tmp);
	}

	int rNumber=0;
	int numberOfDigits=digits.size();
	for (int i = 0; i < numberOfDigits; i++)
	{
		int power=1;
		for (int j = 0; j < i; j++)
		{
			power*=10;
		}
		rNumber+=digits[numberOfDigits-1-i]*power;
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

