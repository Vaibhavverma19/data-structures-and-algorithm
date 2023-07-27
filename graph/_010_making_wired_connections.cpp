class Solution {
public:
    
    unordered_map<int,bool> vis;

    void dfs(int vertex,vector<vector<int> > &adj)
    {
        vis[vertex]=true;
        for(auto neigh:adj[vertex])
        {
            if(vis[neigh]!=true)
            {
                dfs(neigh,adj);
            }
        }
    }

    int makeConnected(int n, vector<vector<int>>& connections) {
        if(connections.size()<n-1)
        return -1;
        vector<vector<int> > adj(n);
        for(int i=0;i<connections.size();++i)
        {
            adj[connections[i][0]].push_back(connections[i][1]);
            adj[connections[i][1]].push_back(connections[i][0]);
        }
       
        int cnt=0;
        for(int i=0;i<n;++i)
        {  if(vis[i]!=true)
           {   cnt++;
               dfs(i,adj);
               
           }

        }
        
       return cnt-1;
    }
};