#include<stdio.h>
#include<algorithm>
#include<vector>
using namespace std;

int main()
{
	vector<bool> output;
	int N;
	scanf("%d",&N);
	for (int i = 0; i < N; i++)
	{
		vector<int> godzilaArmy, mechGodzilaArmy;
		int monster;
		int NG,NM;
		scanf("%d %d",&NG,&NM);
		for (int j = 0; j < NG; j++)
		{
			scanf("%d",&monster);
			godzilaArmy.push_back(monster);
		}
		for (int j = 0; j < NM; j++)
		{
			scanf("%d",&monster);
			mechGodzilaArmy.push_back(monster);
		}
		int GArmySize=godzilaArmy.size();
		int MGArmySize=mechGodzilaArmy.size();
		int G=0;
		int MG=0;
		sort(godzilaArmy.begin(),godzilaArmy.end());
		sort(mechGodzilaArmy.begin(),mechGodzilaArmy.end());
		while (GArmySize!=G && MGArmySize!=MG)
		{
			if (godzilaArmy[G]<mechGodzilaArmy[MG])
			{
				G++;
				continue;
			}
			else
			{
				MG++;
				continue;
			}
		}
		if (MGArmySize==MG)
		{
			output.push_back(1);
		}
		else
		{
			output.push_back(0);
		}
	}

	int outputSize=output.size();
	for (int i = 0; i < outputSize; i++)
	{
		if (output[i])
		{
			printf("Godzilla\n");
		}
		else
		{
			printf("MechaGodzilla\n");
		}
	}

	return 0;
}