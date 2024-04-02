#include<iostream>
using namespace std;
#define INF 9999
void bellman(int edges[][3],int V,int E,int src)
{
	//INITIALIZATION
	int parent[V];
	int d[V];
	int u,v,weightuv;
	for (int i=0;i<V;i++)
	{
		d[i]=INF;
	}
	d[src]=0;
	for (int i=0;i<V-1;i++)
	{
		for (int j=0;j<E;j++)
		{
			u=edges[j][0];
			v=edges[j][1];
			weightuv=edges[j][2];
			if (d[u]!=INF && d[u]+weightuv<d[v])
			{
				d[v]=d[u]+weightuv;
				parent[v]=u;
			}
		}
	}
	for (int i=0;i<E;i++)
	{
		u=edges[i][0];
		v=edges[i][1];
		weightuv=edges[i][2];
		if (d[u]!=INF && d[u]+weightuv<d[v])
		{
			cout<<"Graph contains -ve";
			return;
		}
	}
	cout<<"Vertex | "<<"Distance from source"<<endl;
	for (int i=0;i<V;i++)
	{
		cout<<i<<"      | "<<d[i]<<endl;
	}
}
int main()
{
	int V = 4; // Number of vertices in graph
    int E = 5; // Number of edges in graph
 
    // Every edge has three values (u, v, w) where
    // the edge is from vertex u to v. And weight
    // of the edge is w.
    int edges[][3] = { { 0, 1, 1 }, 
					   { 0, 2, 4 },
                       { 2, 3, 5 }, 
					   { 3, 1, 2 },
                       { 3, 0, 3 }};
 
    bellman(edges, V, E, 0);
}
