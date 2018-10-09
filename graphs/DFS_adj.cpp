
#include<iostream>
#include<bits/stdc++.h>

using namespace std;


class Graph{

	int v;
	list<int> *adj;
public:

	Graph(int vert)
	{
		v=vert;

		adj = new list<int> [vert];
	}


	void addEdge(int u, int v)
	{
		adj[u].push_back(v);
		// adj[v].push_back(u);
	}

	void disp()
	{

		for(int i=0;i<v;i++)
		{
			cout<<i<<"->";

			for(list<int> :: iterator it=adj[i].begin();it!=adj[i].end();it++)
				cout<<(*it)<<"->";

			cout<<endl;
		}
	}


	void DFS_util(int s,vector<bool> &visited)
	{
		visited[s]=true;
		cout<<s<<" ";

		for(list<int> :: iterator it=adj[s].begin();it!=adj[s].end();it++)
		{
			if(visited[(*it)]==false)
				DFS_util((*it),visited);
		}

	}

	void DFS(int s)
	{

		vector<bool> visited(v,false);
		DFS_util(s,visited);
	}


};


int main()
{
	Graph *g = new Graph(8);
	g->addEdge(0, 1); 
    g->addEdge(1, 7); 
    g->addEdge(1, 2); 
    g->addEdge(2, 4); 
    g->addEdge(2, 3); 
    g->addEdge(4, 5);
    g->addEdge(4, 6);
    g->addEdge(7, 4);    

    g->disp();
    g->DFS(0);

	return 1;
}