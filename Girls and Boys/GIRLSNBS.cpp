#include<stdio.h>
#include<vector>
using namespace std;

int main()
{
	vector<int> output;
	int high, low;
	scanf("%d %d", &high, &low);
	while (high != -1 || low != -1)
	{
		if (high < low)
		{
			int tmp = high;
			high = low;
			low = tmp;
		}
		int result;
		if (high % (low + 1))
		{
			result = (high / (low+1)) + 1;
		}
		else
		{
			result = high / (low+1);
		}
		output.push_back(result);
		scanf("%d %d", &high, &low);
	}

	int outputSize = output.size();
	for (int i = 0; i < outputSize; i++)
	{
		printf("%d\n", output[i]);
	}

	return 0;
}