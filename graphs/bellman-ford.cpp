#include <iostream>
#include <bits/stdc++.h>
#define inf INT_MAX

using namespace std;

struct edge{
	int src;
	int dest;
	int weight;
};


class graph{

	int v;
	int e;
	struct edge *edges;
	int ecount;
public:
	graph(int vert, int eds)
	{
		v=vert;
		e=eds;
		edges = new edge[e];
		ecount = 0;
	}

	void addEdge(int u,int v,int w)
	{
		
		edges[ecount].src = u;
		edges[ecount].dest = v;
		edges[ecount].weight = w;
		ecount+=1;
			
	}


	void disp()
	{
		for(int i=0;i<e;i++)
			cout<<"("<<edges[i].src<<","<<edges[i].dest<<","<<edges[i].weight<<")"<<endl;

	}

	vector<int> bellman_ford(int s)
	{
		vector<int> dist(v,inf);
		dist[s]=0;

		for(int i=1;i<=v-1;i++)
		{
			for(int j=0;j<e;j++)
			{
				int u = edges[j].src;
				int v = edges[j].dest;
				int w = edges[j].weight;

				if(dist[u]!= inf && dist[v]>dist[u]+w)
					dist[v] = dist[u] + w;
			}
		}


		for(int j=0;j<e;j++)
		{
			int u = edges[j].src;
			int v = edges[j].dest;
			int w = edges[j].weight;

			if(dist[u]!= inf && dist[v]>dist[u]+w)
				{
					cout<<"Negative Cycle!!"<<endl;
					dist[s]=-1;
					return dist;
				}
		}

		return dist;

	}

};

int main()
{
	graph *g = new graph(5,8);

	g->addEdge(0,1,-1);
	g->addEdge(0,2,4);
	g->addEdge(1,2,3);
	g->addEdge(1,3,2);
	g->addEdge(1,4,2);
	g->addEdge(3,2,5);
	g->addEdge(3,1,1);
	g->addEdge(4,3,-3);
	
	vector<int> d = g->bellman_ford(0);

	if(d[0]!=-1)
	{
		for(int i=0;i<d.size();i++)
			cout<<d[i]<<" ";
	}
	
	
	

	return 0;
}