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

		adj = new list<int> [v];

	}


	void addEdge(int u,int v)
	{
		adj[u].push_back(v);
		adj[v].push_back(u);

	}


	void disp()
	{
		for(int i=0;i<v;i++)
		{
			cout<<i<<"->";
			list<int> :: iterator it;
			for(it=adj[i].begin();it!=adj[i].end();it++)
				cout<<(*it)<<"->";

			cout<<endl;
		}
	}



	void BFS(int s)
	{

		vector<bool> visited(v,false);

		queue<int> q;
		q.push(s);
		visited[s]=true;


		while(!q.empty())
		{
			int u =q.front();
			cout<<u<<" ";
			q.pop();

			for(list<int>:: iterator it=adj[u].begin();it!=adj[u].end();it++)
			{
				if(visited[(*it)]==false)
				{
					visited[(*it)] = true;
					q.push((*it));
				}
			}
		}

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

    g->BFS(0);
	return 0;
}