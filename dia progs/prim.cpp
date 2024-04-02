#include<iostream>
#include<limits.h>
using namespace std;
int V;
int graph[5][5];
int minwt(int weight[],bool mstSet[])
{
	int min=INT_MAX,min_index;
	for (int v=0;v<V;v++)
	{
		cout<<"minwt"<<" ";
		if (mstSet[v]==false && weight[v]<min)
		{
			min=weight[v];
			min_index=v;
		}
	}
	return min_index;
}
void printMST(int parent[])
{
	cout<<"Edge"<<" "<<"Weight"<<endl;
	for (int i=1;i<V;i++)
	{
		cout<<parent[i]<<"-"<<i<<"  "<<graph[i][parent[i]]<<endl;
	}
}
void prims()
{
	bool mstSet[V];
	int weight[V];
	int parent[V];
	for (int i=0;i<V;i++)
	{
		mstSet[i]=false;
		weight[i]=INT_MAX;
	}
	parent[0]=-1;
	weight[0]=0;
	for (int count=0;count<V-1;count++)
	{
		int u=minwt(weight,mstSet);
		mstSet[u]=true;
		for (int v=0;v<V;v++)
		{
			cout<<"v"<<v<<" ";
			if (graph[u][v] && mstSet[v]==false && graph[u][v]<weight[v])
			{
				weight[v]=graph[u][v];
				parent[v]=u;
			}
		}
		cout<<"Count"<<count<<endl;
	}
	printMST(parent);
}
int main()
{
	cout<<"Enter num of vertices:";
	cin>>V;
	for (int i=0;i<V;i++)
	{
		for (int j=0;j<V;j++)
		{
			graph[i][j]=-1;
		}
	}
	for (int i=0;i<V;i++)
	{
		for (int j=0;j<V;j++)
		{
			if (graph[i][j]<0)
			{
				cout<<"Enter weight of "<<i<<" to "<<j<<":";
			    cin>>graph[i][j];
			    graph[j][i]=graph[i][j];
			}
		}
	}
	prims();
}
