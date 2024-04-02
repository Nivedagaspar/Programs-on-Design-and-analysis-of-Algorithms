#include <bits/stdc++.h>
using namespace std;
void BellmanFord(int edges[][3], int V, int E,int src)
{
    // Initialize distance of all vertices as infinite.
    int parent[V];
    int dis[V];
    for (int i = 0; i < V; i++)
        dis[i] = INT_MAX;
 
    // initialize distance of source as 0
    dis[src] = 0;
 
    // Relax all edges |V| - 1 times.
    int u,v,weightuv;
    for (int i = 0; i < V - 1; i++) 
	{
        for (int j = 0; j < E; j++) 
		{
			/*relaxation:
			  if d[u] + w(u,v) < d[v]
			     d[v]=d[u]+w(u,v)*/
			u=edges[j][0];
			v=edges[j][1];
			weightuv=edges[j][2];
            if (dis[u] != INT_MAX && dis[u] + weightuv < dis[v])
                {
                	dis[v] = dis[u] + weightuv;
                	parent[v]=u;
				}
        }
    }
 
    // check for negative-weight cycles.
    for (int i = 0; i < E; i++) 
	{
        u = edges[i][0];
        v = edges[i][1];
        weightuv = edges[i][2];
        if (dis[u] != INT_MAX && dis[u] + weightuv < dis[v])
            cout << "Graph contains negative weight cycle"<< endl;
    }
 
    cout << "Vertex Distance from Source" << endl;
    for (int i = 0; i < V; i++)
        cout << i << "\t\t" << dis[i] << endl;
    cout<<"Edge "<<"weight"<<endl;
    for (int i=1;i<V;i++)
    {
    	int wgt;
    	for (int j=0;j<E;j++)
    	{
    		if (edges[j][0]==parent[i] && edges[j][1]==i)
    		    wgt=edges[j][2];
		}
    	cout<<parent[i]<<"-"<<i<<"  "<<wgt<<endl;
	}
}
 
// Driver program to test above functions
int main()
{
    int V = 6; // Number of vertices in graph
    int E = 9; // Number of edges in graph
 
    // Every edge has three values (u, v, w) where
    // the edge is from vertex u to v. And weight
    // of the edge is w.
    int edges[][3] = { { 0, 1, 6 }, 
					   { 0, 2, 4 },
                       { 0, 3, 5 }, 
					   { 1, 4, -1 },
                       { 2, 1, -2 }, 
					   { 2, 4, 3 },
                       { 3, 2, -2 }, 
					   { 3, 5, -1 },
					   { 4, 5, 3 }};
 
    BellmanFord(edges, V, E, 0);
    return 0;
}
