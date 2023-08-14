#include <bits/stdc++.h> 
#include<unordered_map>
vector<pair<pair<int, int>, int>> calculatePrimsMST(int n, int m, vector<pair<pair<int, int>, int>> &g)
{
    unordered_map<int,list<pair<int,int>> > adjList;
    for(int i=0;i<g.size();++i)
    {
        int u=g[i].first.first;
        int v=g[i].first.second;
        int w=g[i].second;
        adjList[u].push_back({v,w});
        adjList[v].push_back({u,w});
    }

    vector<int> key(n+1,INT_MAX);
    vector<int> parent(n+1,-1);
    vector<bool> mst(n+1,false);

    key[1]=0;
    for(int i=1;i<=n;++i)
    {
        //1. find minimum key.
        int mini=INT_MAX;
        int node;
        for(int j=1;j<=n;++j)
        {
            if(key[j]<mini && mst[j]!=true)
            {
                mini=key[j];
                node=j;
            }
        }
        
        //2.mark this node as true.
        mst[node]=true;

        //3. visit its adjacent nodes and update their keys.
        for(auto it:adjList[node])
        {
            int neigh=it.first;
            int w=it.second;
            if(key[neigh]>w && mst[neigh]!=true)
            {
                key[neigh]=w;
                parent[neigh]=node;
            }

        }
    }
    vector<pair<pair<int,int>, int>> ans;
    for(int i=2;i<=n;++i)
    {
        int a=parent[i];
        int b=i;
        int wt=key[i];
        ans.push_back({{a,b},wt});
    }
    return ans;
}
