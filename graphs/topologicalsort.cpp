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


	void addEdge(int u,int v)
	{
		adj[u].push_back(v);
	}


	void disp()
	{
		for(int i=0;i<v;i++)
		{
			cout<<i<<"->";
			for(list<int> :: iterator it = adj[i].begin();it!= adj[i].end();it++)
				cout<<(*it)<<"->";

			cout<<endl;
		}
	}


	void topologicalsort()
	{

		vector<int> indegree(v,0);

		for(int i=0;i<v;i++)
		{
			for(list<int> :: iterator it=adj[i].begin();it!=adj[i].end();it++)
				indegree[(*it)]+=1;
		}


		queue<int> q;
		for(int i=0;i<v;i++)
		{
			if(indegree[i]==0)
				q.push(i);
		}
		int count=0;

		vector<int> top_order;

		while(!q.empty())
		{
			int u = q.front();
			q.pop();
			top_order.push_back(u);
			count++;

			for(list<int> :: iterator it=adj[u].begin(); it!= adj[u].end();it++)
			{
				if(--indegree[(*it)]==0)
					q.push((*it));
			}

		}

		if(count!=v)
		{
			cout<<"There is a cycle!";
			return;
		}

		for(int i=0;i<top_order.size();i++)
			cout<<top_order[i]<<" ";

		cout<<endl;




	}
};



int main()
{
	Graph *g = new Graph(6);
	g->addEdge(5, 2); 
    g->addEdge(5, 0); 
    g->addEdge(4, 0); 
    g->addEdge(4, 1); 
    g->addEdge(2, 3); 
    g->addEdge(3, 1); 

    //g->disp();

    g->topologicalsort();

  

	return 1;
}