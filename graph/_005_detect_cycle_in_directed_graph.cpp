//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
  //use vector instead of map otherwise soln will show tle.
   bool dfscycle(int vertex,vector<int> adj[],map<int,bool>& vis,map<int,bool>& dfsvis)
   {
       vis[vertex]=true;
       dfsvis[vertex]=true;
       for(auto neigh:adj[vertex])
       {
           if(vis[neigh]==true && dfsvis[neigh]==true)
           {   //cout<<"neighbour is "<<neigh<<" , vertex is "<<vertex;
               return true;
           }
           if(vis[neigh]!=true)
           {
               bool ans=dfscycle(neigh,adj,vis,dfsvis);
              
               if(ans==true)
               return true;
           }
           
        }
        dfsvis[vertex]=false;
        return false;
   }
    // Function to detect cycle in a directed graph.
    bool isCyclic(int V, vector<int> adj[]) {
     map<int,bool> vis;
     map<int,bool> dfsvis;
     bool ans;
      for(int i=0;i<V;++i)
      {
          if(!vis[i])
          {
              ans=dfscycle(i,adj,vis,dfsvis);
              if(ans==true)
              {
                  return true;
              }
             // dfsvis[i]=false;
          }
      }
      return false;
    }
};

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        cout << obj.isCyclic(V, adj) << "\n";
    }

    return 0;
}

// } Driver Code Ends