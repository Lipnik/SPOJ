#include<stdio.h>
#include<string.h>
#include<vector>
using namespace std;

int main()
{
	vector<char*> output;
	char* bishops=new char[103];
	char* size=bishops+1;
	while (scanf("%s",size)!=EOF)
	{	
		if (strlen(size)==1 && *size=='1')
		{
			bishops=size;
		}
		else
		{
			int length=strlen(size);
			int carry=-2;		
			for (int i = length-1; i >=0; i--)
			{
				int digit=size[i]-48;
				digit=2*digit+carry;
				if (digit<0)
				{
					digit+=10;
					carry=-1;
				}
				else
				{
					carry=digit/10;
					digit%=10;
				}
				size[i]=digit+48;
			}
			if (carry!=0)
			{
				bishops[0]=carry+48;			
			}
			else
			{
				bishops=size;
			}		
		}
		output.push_back(bishops);
		bishops=new char[103];
		size=bishops+1;
	}

	int outputSize=output.size();
	for (int i = 0; i < outputSize; i++)
	{
		printf("%s\n",output[i]);
	}
	return 0;
}