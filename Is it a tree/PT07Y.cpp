#include<stdio.h>
#include<vector>
#include<map>
using namespace std;

bool IsTree(int vertex,vector<int>* vertices, bool* visited,int* N,int previous=-1)
{
	visited[vertex]=1;
	*N=*N-1;
	int size=vertices[vertex].size();
	for (int i = 0; i < size; i++)
	{
		int nextVertex=vertices[vertex][i];
		if (nextVertex!=previous)
		{
			if (visited[nextVertex])
			{
				return 0;
			}
			else
			{
				if (IsTree(nextVertex,vertices,visited,N,vertex))
				{
					continue;
				}
				else
				{
					return 0;
				}
			}
		}
		else
		{
			continue;
		}
	}
	return 1;
}

int main()
{
	bool output;
	int N,M;
	scanf("%d %d",&N,&M);
	vector<int>* vertices=new vector<int>[N+1];
	bool* visited=new bool[N+1];
	for (int i = 0; i < N+1; i++)
	{
		visited[i]=0;
	}
	int v1,v2;
	for (int i = 0; i < M; i++)
	{
		scanf("%d %d",&v1,&v2);
		vertices[v1].push_back(v2);
		vertices[v2].push_back(v1);
	}
	if (M!=N-1)
	{
		output=0;
	}
	else
	{
		output=IsTree(1,vertices,visited,&N);
	}
	if (output)
	{
		if (N==0)
		{
			printf("YES\n");
		}
		else
		{
			printf("NO\n");
		}
	}
	else
	{
		printf("NO\n");
	}
	return 0;
}