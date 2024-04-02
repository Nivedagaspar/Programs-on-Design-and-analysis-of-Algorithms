#include<iostream>
using namespace std;
int V;
int graph[10][10];
void floyd()
{
	for (int k=0;k<V;k++)
	{
		for (int i=0;i<V;i++)
		{
			for (int j=0;j<V;j++)
			{
				if (graph[i][k]+graph[k][j]<graph[i][j])
				{
					graph[i][j]=graph[i][k]+graph[k][j];
				}
			}
		}
	}
	for (int i=0;i<V;i++)
		{
			for (int j=0;j<V;j++)
			{
				cout<<graph[i][j]<<" ";
			}
			cout<<endl;
		}
}
int main()
{
	cout<<"Enter number of vertices:";
	cin>>V;
	for (int i=0;i<V;i++)
	{
		for (int j=0;j<V;j++)
		{
			cout<<"Enter weight of edge "<<i<<j<<":";
			cin>>graph[i][j];
		}
	}
	floyd();
}
