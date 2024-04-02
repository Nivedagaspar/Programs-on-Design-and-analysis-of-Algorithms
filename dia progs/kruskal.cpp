#include<iostream>
#include<limits.h>
using namespace std;
int V=5;
int graph[5][5] = { { 0, 2, 0, 6, 0 },
						{ 2, 0, 3, 8, 5 },
						{ 0, 3, 0, 0, 7 },
						{ 6, 8, 0, 0, 9 },
						{ 0, 5, 7, 9, 0 } };
void printMST(int parent[])
{
	cout<<"Edge"<<" "<<"Weight"<<endl;
	for (int i=1;i<V;i++)
	{
		cout<<parent[i]<<"-"<<i<<"  "<<graph[i][parent[i]]<<endl;
	}
}
void minedge(bool mstSet[],int &parent,int &vertex)
{
	int min=INT_MAX;
	int prnt,vtx;
	for (int u=0;u<V;u++)
	{
		for (int v=0;v<V;v++)
		{
			if (graph[u][v]<min && (mstSet[u]!=true || mstSet[v]!=true) && graph[u][v]!=0)
			{
				min=graph[u][v];
				cout<<"Parent:"<<u<<" vertex:"<<v<<endl;
				prnt=u;
				vtx=v;
			}
		}
	}
	parent=prnt;
	vertex=vtx;
}
bool completed(bool mstSet[])
{
	bool flag=true;
	for (int i=0;i<V;i++)
	{
		if (mstSet[i]==false)
		{
			flag=false;
			break;
		}
	}
	return flag;
}
void kruskal()
{
	bool mstSet[V];
	int parent[V];
	int prnt,vtx;
	for (int i=0;i<V;i++)
	{
		mstSet[V]=false;
	}
	while (completed(mstSet)==false)
	{
		minedge(mstSet,prnt,vtx);
		parent[vtx]=prnt;
		mstSet[prnt]=true;
		mstSet[vtx]=true;	
	}
	printMST(parent);
}
int main()
{
	kruskal();
}
