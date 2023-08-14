#include <bits/stdc++.h> 
bool detectcycleindirectedGraph( vector<vector<int> >& adj,vector<bool>& vis,vector<bool>& dfsvis,int node,int parent)
{
    vis[node]=true;
    dfsvis[node]=true;
    for(auto neighbor:adj[node])
    {
               
            if(vis[neighbor]!=true)
            {
                bool ans=detectcycleindirectedGraph(adj,vis,dfsvis,neighbor,node);
                if(ans)
                {
                    return true;
                }
            }
            if( dfsvis[neighbor]==true)
            {
                return true;
            }
    
    }
    dfsvis[node]=false;
    return false;
}
bool canWin(int n, int m, vector<vector<int>> &edges)
{  
     vector<vector<int> > adj(n);
    for(int i=0;i<edges.size();++i)
    {
        adj[edges[i][0]].push_back(edges[i][1]); // {2,1} measn 2->{1}.
    }
    vector<bool> vis(n,false);
    vector<bool> dfsvis(n,false);
    bool iscycle=detectcycleindirectedGraph(adj,vis,dfsvis,0,0);
    if(iscycle)
    {
        return false;
        
    }
   return true;
    
}
