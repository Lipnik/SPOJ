#include<stdio.h>
#include<vector>
using namespace std;

int main()
{
	vector<int> output;
	float target;
	scanf("%f",&target);
	do
	{
		int cards=0;
		float hangover=0;
		do
		{
			cards++;
			hangover+=1./(cards+1);
		} while (hangover<target);
		output.push_back(cards);

		scanf("%f",&target);
	} while (target>0);

	int outputSize=output.size();
	for (int i = 0; i < outputSize; i++)
	{
		printf("%d card(s)\n",output[i]);
	}
	return 0;
}