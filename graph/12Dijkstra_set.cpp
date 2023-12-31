//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
	public:
	//Function to find the shortest distance of all the vertices
    //from the source vertex S.
    vector <int> dijkstra(int V, vector<vector<int>> adj[], int S)
    {
        vector<int> dist(V,INT_MAX);
        set<pair<int,int> > paths;
        paths.insert({0,S});
        dist[S]=0;
        while(!paths.empty())
        {
            auto top=*(paths.begin());
            paths.erase(top);
            //top will get the pair of{dist,node}
            int nodedist=top.first;
            int node=top.second;
            
            for(auto i:adj[node])
            {   int neigh=i[0];
                int d=i[1];
            
                if(dist[neigh]>dist[node]+d)
                {   auto presentalready=paths.find({dist[neigh],neigh});
                  if(presentalready!=paths.end())
                  {
                      paths.erase(presentalready);
                  }
                    dist[neigh]=dist[node]+d;
                    paths.insert({dist[neigh],neigh});
                }
            }
            
            
        }
        
        return dist;
    }
};


//{ Driver Code Starts.


int main()
{
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> adj[V];
        int i=0;
        while (i++<E) {
            int u, v, w;
            cin >> u >> v >> w;
            vector<int> t1,t2;
            t1.push_back(v);
            t1.push_back(w);
            adj[u].push_back(t1);
            t2.push_back(u);
            t2.push_back(w);
            adj[v].push_back(t2);
        }
        int S;
        cin>>S;
        
        Solution obj;
    	vector<int> res = obj.dijkstra(V, adj, S);
    	
    	for(int i=0; i<V; i++)
    	    cout<<res[i]<<" ";
    	cout<<endl;
    }

    return 0;
}


// } Driver Code Ends