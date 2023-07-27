#include <bits/stdc++.h> 
void toposort(int vertex,int n,vector<vector<int> > &adj,vector<int> &topo)
{
    vector<int> indegree(n,0);
    for(int i=0;i<adj.size();++i)
    {
        for(int j=0;j<adj[i].size();++j)
        {
            indegree[adj[i][j]]+=1;
        }
    }
    queue<int> q;
    for(int i=0;i<indegree.size();++i)
    {
        if(indegree[i]==0)
        {
            q.push(i);
        }
    }

    while(!q.empty())
    {   int vertex=q.front();
    q.pop();
        topo.push_back(vertex);
        for(auto j:adj[vertex])
        {
            indegree[j]-=1;
            if(indegree[j]==0)
            {
                q.push(j);
            }
        }
    }
}
vector<int> minTime(int n, int m, vector<vector<int>> &edges)
{
    vector<vector<int> > adj(n);
    for(int i=0;i<edges.size();++i)
    {
        adj[edges[i][0]].push_back(edges[i][1]);
        //adj[edges[i][1]].push_back(edges[i][0]);
    }
    
    vector<int> topo;
    toposort(0,n,adj,topo);
    vector<int> dist(n,1);
     //dist[topo[0]]=1;
    for(auto i:topo)
    {
        for(auto neigh:adj[i])
        {
          if(dist[neigh]<dist[i]+1)
          {
              dist[neigh]=dist[i]+1;
          }
        }
    }

    return dist;


}
