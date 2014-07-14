#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;

int main()
{
	vector<bool> output;
	int A, D;
	scanf("%d %d", &A, &D);
	while (A != 0 || D != 0)
	{
		vector<int> attack;
		vector<int> defence;
		int distance;
		for (int i = 0; i < A; i++)
		{
			scanf("%d",&distance);
			attack.push_back(distance);
		}
		for (int i = 0; i < D; i++)
		{
			scanf("%d", &distance);
			defence.push_back(distance);
		}
		sort(attack.begin(), attack.end());
		sort(defence.begin(), defence.end());
		if (attack[0] < defence[1])
		{
			output.push_back(1);
		}
		else
		{
			output.push_back(0);
		}
		scanf("%d %d", &A, &D);
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