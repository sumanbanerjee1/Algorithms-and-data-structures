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


	void print_parents(int s,int d,vector<int> &parent)
	{
		cout<<endl<<endl;
		int i=s;
		while(i!=d)
		{
			cout<<i<<"==";
			i=parent[i];
		}
		cout<<d;
	}

	bool cyc(int s,vector<bool> &visited,vector<bool> &recstack, vector<int> &parent)
	{
		if(visited[s]==false)
		{
			visited[s]=true;
			recstack[s]=true;
			for(list<int> :: iterator it=adj[s].begin();it!=adj[s].end();it++)
			{
				if(visited[(*it)]==false)	
					{
						parent[(*it)] = s;
						if(cyc((*it),visited,recstack,parent))
							return true;
					}
				
				else if(recstack[(*it)]==true)
					{
						print_parents(s,(*it),parent);
						return true;
					}
			}

		}
		recstack[s]=false;
		return false;
	}

	void iscycl()
	{
		vector<bool> visited(v,false);
		vector<bool> recstack(v,false);
		vector<int> parent(v,-1);

		if(cyc(0,visited,recstack,parent))
			cout<<"There"<<endl;
		else
			cout<<"No Cycle"<<endl;

	}


	


};

int main()
{
	Graph *g = new Graph(8);
	g->addEdge(0, 1); 
    g->addEdge(7, 1); 
    g->addEdge(1, 2); 
    g->addEdge(2, 4); 
    g->addEdge(2, 3); 
    g->addEdge(4, 5);
    g->addEdge(4, 6);
    g->addEdge(4, 7);

    g->disp();

    g->iscycl();

	return 1;
}