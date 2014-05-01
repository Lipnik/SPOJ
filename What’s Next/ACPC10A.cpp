#include<stdio.h>
#include<vector>
using namespace std;

int main()
{
	char AP[3]={'A','P',0};
	char GP[3]={'G','P',0};
	vector<char*> output1;
	vector<int> output2;
	int a1,a2,a3;
	scanf("%d %d %d",&a1,&a2,&a3);
	do
	{
		int next;
		if (a2-a1==a3-a2 && a3-a2!=0)//AP
		{
			next=a3+a3-a2;
			output1.push_back(AP);
			
		}
		else//GP
		{
			next=a3*a3/a2;
			output1.push_back(GP);
		}
		output2.push_back(next);
		scanf("%d %d %d",&a1,&a2,&a3);
	} while (a1!=0 || a2!=0 || a3!=0);

	int outputSize=output1.size();
	for (int i = 0; i < outputSize; i++)
	{
		printf("%s %d\n",output1[i],output2[i]);
	}
	return 0;
}