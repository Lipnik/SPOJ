#include<stdio.h>
#include<math.h>
#include<vector>

using namespace std;

int main()
{
	vector<bool> output;
	int input;
	scanf("%d", &input);
	while (input!=-1)
	{
		if ((input-1)%6)
		{
			output.push_back(0);
		}
		else
		{
			int x = (input - 1) / 3;
			double n = (sqrt(1+4*x)-1) / 2;
			n = remainder(n, 1);
			if (n!=0)
			{
				output.push_back(0);
			}
			else
			{
				output.push_back(1);
			}
		}
		scanf("%d", &input);
	}

	int outputSize = output.size();
	for (int i = 0; i < outputSize; i++)
	{
		if (output[i])
		{
			printf("Y\n");
		}
		else
		{
			printf("N\n");
		}
	}
	return 0;
}