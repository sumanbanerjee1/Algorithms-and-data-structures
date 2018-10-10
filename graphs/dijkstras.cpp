#include<iostream>
#include<bits/stdc++.h>
#define inf INT_MAX
using namespace std;

typedef pair<int,int> iPair;

class graph{

	int v;
	list< pair<int,int> > *adj;

public:

	graph(int vert)
	{
		v=vert;
		adj = new list< pair<int,int> > [vert];
	}


	void addEdge(int u,int v,int w)
	{
		adj[u].push_back(make_pair(w,v));
		adj[v].push_back(make_pair(w,u));
	}

	void disp()
	{
		for(int i=0;i<v;i++)
		{
			cout<<i<<"->";
			for( list<iPair> :: iterator j = adj[i].begin();j!=adj[i].end();j++)
				cout<<"("<<(*j).second<<","<<(*j).first<<")->";

			cout<<endl;
		}
	}


	void dijkstras(int s)
	{
		vector<int> dist(v,inf);
		dist[s]=0;

		priority_queue < iPair, vector<iPair> , greater<iPair> > pq;
		
		pq.push(make_pair(0,s));

		while(!pq.empty())
		{
			int u = pq.top().second;
			pq.pop();

			for( list<iPair> :: iterator j = adj[u].begin(); j!=adj[u].end(); j++)
			{
				int node = (*j).second;
				if(dist[node] > dist[u] + (*j).first)
				{
					dist[node] = dist[u] + (*j).first;
					pq.push(make_pair(dist[node],node));
				}
			}
		}



		for(int i=0;i<v;i++)
		{
			cout<<"Vertex :"<<i<<" == "<<dist[i]<<endl;
		}
	}

};


int main()
{
	graph *g = new graph(9);
	g->addEdge( 0, 1, 4); 
    g->addEdge( 0, 7, 8); 
    g->addEdge( 1, 2, 8); 
    g->addEdge( 1, 7, 11); 
    g->addEdge( 2, 3, 7); 
    g->addEdge( 2, 8, 2); 
    g->addEdge( 2, 5, 4); 
    g->addEdge( 3, 4, 9); 
    g->addEdge( 3, 5, 14); 
    g->addEdge( 4, 5, 10); 
    g->addEdge( 5, 6, 2); 
    g->addEdge( 6, 7, 1); 
    g->addEdge( 6, 8, 6); 
    g->addEdge( 7, 8, 7); 

    g->dijkstras(0);
	return 0;
}
