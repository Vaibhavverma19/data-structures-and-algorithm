//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    // Function to detect cycle in an undirected graph.
    bool helper(int src,vector<int> adj[],map<int,bool>& vis,map<int,int>& parent)
    {
        queue<int> q;
        q.push(src);
        vis[src]=true;
        parent[src]=src;
        while(!q.empty())
        {
            int vertex=q.front();
            q.pop();
            //visit all neightbors of this vertex
            for(auto neigh:adj[vertex])
            {
                if(vis[neigh]==true && parent[vertex]!=neigh)
                {   //cout<<src<<","<<neigh<<","<<vertex<<","<<parent[vertex];
                    return true;
                }
                else{ if(vis[neigh]!=true)
                        {
                            vis[neigh]=true;
                            q.push(neigh);
                            parent[neigh]=vertex;
                        }
                }
            }
        }
        return false;
    }
    bool isCycle(int V, vector<int> adj[]) {
        map<int,bool> vis;
        map<int,int> parent;
        bool ans=false;
        for(int i=0;i<V;++i)
        {
            if(!vis[i])
            {
               ans=helper(i,adj,vis,parent);
               if(ans==true)
               {
                   return true;
               }
            }
        }
        return false;
        
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;
        vector<int> adj[V];
        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        Solution obj;
        bool ans = obj.isCycle(V, adj);
        if (ans)
            cout << "1\n";
        else
            cout << "0\n";
    }
    return 0;
}
// } Driver Code Ends