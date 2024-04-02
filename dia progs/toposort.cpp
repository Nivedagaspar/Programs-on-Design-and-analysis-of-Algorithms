#include<iostream>
#include<list>
#include<stack>
using namespace std;
class Graph
{
	int V;
	list<int>* adj;
	public:
	Graph(int V)
	{
		this->V=V;
		adj= new list<int>[V];
	}
	void addedge(int parent,int v)
	{
		adj[parent].push_back(v);
	}
	void toposortadjstack(int v,bool visited[],stack<int>& Stack)
	{
		visited[v] = true;
		list<int>::iterator i;
		for (i=adj[v].begin();i!=adj[v].end();++i)
		{
			if (visited[*i]==false)
			    toposortadjstack(*i,visited,Stack);
		}
		Stack.push(v);
	}
	void toposort()
	{
		bool* visited= new bool[V];
		stack<int> Stack;
		for (int i=0;i<V;i++)
		{
			visited[i]=false;
		}
		for (int i=0;i<V;i++)
		{
			if(visited[i]==false)
			   toposortadjstack(i,visited,Stack);
		}
		while(!Stack.empty())
		{
			cout<<Stack.top()<<" ";
			Stack.pop();
		}
		
	}
};
int main()
{
	Graph g(6);
	g.addedge(5,0);
	g.addedge(5,2);
	g.addedge(4,0);
	g.addedge(4,1);
	g.addedge(2,3);
	g.addedge(3,1);
	g.toposort();
}
