#include <iostream>
#include <bits/stdc++.h>

using namespace std;


class graph{

	int v;
	list<int> *ad;
public:


	graph(int vert)
	{
		v=vert;
		ad = new list<int> [vert];
	}


	void addEdge(int u,int v)
	{
		ad[u].push_back(v);
	}


	void disp()
	{
		for(int i=0;i<v;i++)
		{
			cout<<i<<"->";

			for(list<int> :: iterator j = ad[i].begin(); j!=ad[i].end();j++)
				cout<<(*j)<<"->";

			cout<<endl;
		}
	}

	void DFS_order(int s,vector<bool> &visited, stack<int> &st)
	{
		visited[s]=true;

		for(list<int> :: iterator j = ad[s].begin(); j!=ad[s].end();j++)
		{
			int node =(*j);
			if(visited[node]==false)
				DFS_order(node,visited,st);
		}

		st.push(s);

	}

	graph * get_trans()
	{
		graph *gr = new graph(v);

		for(int i=0;i<v;i++)
		{
			for(list<int> :: iterator j = ad[i].begin(); j!=ad[i].end();j++)
				gr->addEdge((*j),i);
		}

		return gr;

	}


	void DFS(int s,vector<bool> &visited)
	{
		visited[s]=true;
		cout<<s<<" ";

		for(list<int> :: iterator j = ad[s].begin(); j!=ad[s].end();j++)
		{
			int node =(*j);
			if(visited[node]==false)
				DFS(node,visited);
		}


	}

	void scc()
	{
		vector<bool> visited(v,false);
		stack<int> st;

		for(int i=0;i<v;i++)
		{
			if(visited[i]==false)
				DFS_order(i,visited,st);
		}

		graph *gr = this->get_trans();

		for(int i=0;i<v;i++)
			visited[i] = false;

		while(!st.empty())
		{
			int t = st.top();
			st.pop();
			if(visited[t]==false)
			{
				gr->DFS(t,visited);
				cout<<endl;
			}	
			
		}
		
	}




};




int main()
{
	graph *g = new graph(5);
	g->addEdge(1, 0); 
    g->addEdge(0, 2); 
    g->addEdge(2, 1); 
    g->addEdge(0, 3); 
    g->addEdge(3, 4); 

	g->scc();


	return 0;
}