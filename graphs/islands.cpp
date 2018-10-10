#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <bits/stdc++.h>
using namespace std;


void disp(vector< vector <int> > &T,int n,int m)
{
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
            cout<<T[i][j]<<" ";
        
        cout<<endl;
    }
    
}


bool isSafe(vector< vector <int> > &T, int i, int j,int n,int m)
{
    if(i<0 || j <0 || i>=n || j>=m)
        return false;
    else
    {
        if(T[i][j])
            return true;
        else
            return false;
    }
    
    
}

void DFS(vector< vector <int> > &T,int i,int j,int n,int m,vector< vector <int> > &visited)
{
    static int rw[] = {0,-1,-1,-1,0,1,1,1};
    static int cl[] = {-1,-1,0,1,1,1,0,-1};
    
    for(int k=0;k<8;k++)
    {
        int ni = rw[k]+i;
        int nj = cl[k]+j;
        if(isSafe(T,ni,nj,n,m) && T[i][j])
        {  
            if(!visited[ni][nj])
            {
                visited[ni][nj]=1;
                DFS(T,ni,nj,n,m,visited);
            }
            
        }
    }
    
}


int DFS_util(vector< vector <int> > &T,int n,int m)
{
    vector< vector <int> > visited;
    visited.resize(n, vector<int> (m));
    
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
            visited[i][j]=0;
    }
    
    int cnt=0;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(!visited[i][j] && T[i][j])
            {
                cnt+=1;
                DFS(T,i,j,n,m,visited);
            }
                
        }
    }
    return cnt;
}


int main() {
    int n,m;
    cin>>n>>m;
    vector< vector<int> > T;
    T.resize(n, vector<int> (m));
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
            cin>>T[i][j];
        
    }
    
    cout<<DFS_util(T,n,m)<<endl;
    
    
    return 0;
}

