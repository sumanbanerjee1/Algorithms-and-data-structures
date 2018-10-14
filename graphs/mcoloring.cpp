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
		ad[v].push_back(u);
	}

	void disp()
	{
		for(int i=0;i<v;i++)
		{
			cout<<i<<"->";

			for(list<int> :: iterator j = ad[i].begin();j!=ad[i].end();j++)
				cout<<(*j)<<"->";
			cout<<endl;
		}
	}

	bool isSafe(vector<int> &color,int vert,int c)
	{
		for( list<int> :: iterator j = ad[vert].begin();j!=ad[vert].end();j++)
		{
			if(color[(*j)]==c)
				return false;
		}

		return true;

	}

	bool mcol(vector<int> &color,int vert,int m)
	{
		if(vert==v)
			return true;

		for(int c=1;c<=m;c++)
		{
			if(isSafe(color,vert,c))
			{
				color[vert]=c;
				if(mcol(color,vert+1,m))
					return true;
				color[vert]=0;
			}
		}

		return false;
	}


	void printsol(vector<int> color)
	{
		for(int i=0;i<v;i++)
			cout<<color[i]<<" ";

		cout<<endl;
	}

	void ismcol(int m)
	{
		vector<int> color(v,0);
		if(mcol(color,0,m))
			printsol(color);
		else
			cout<<"No Solution!!";

	}

};




int main()
{
	graph *g = new graph(4);

	g->addEdge(0,1);
	g->addEdge(0,2);
	g->addEdge(0,3);
	g->addEdge(2,3);
	g->addEdge(1,2);
	
	g->ismcol(3);
	
	return 0;
}