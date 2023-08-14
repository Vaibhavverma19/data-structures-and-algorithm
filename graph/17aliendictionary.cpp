//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
    public:
    void toposort(vector<vector<int> >& adjList,vector<int>& topo,int k)
    {
        vector<int> indegree(k,0);
        
        for(int i=0;i<adjList.size();++i)
        {
           for(auto j:adjList[i])
           {
               indegree[j]+=1;
           }
        }
        queue<int> q;
        for(int i=0;i<k;++i)
        {
            if(indegree[i]==0)
            {
                q.push(i);
            }
        }
        
        while(!q.empty())
        {
            auto node=q.front();
            q.pop();
            topo.push_back(node);
            for(auto neigh:adjList[node])
            {
                indegree[neigh]-=1;
                if(indegree[neigh]==0)
                {
                    q.push(neigh);
                }
            }
            
        }
        
    }
    string findOrder(string dict[], int N, int K) {
      vector<vector<int> > adjList(K);
      int l= N;
    
      for(int i=1;i<l;++i)
      {  
          string word1=dict[i-1];
          string word2=dict[i];
          int len=min(word1.length(),word2.length());
          for(int j=0;j<len;++j)
          {
              if(word1[j]!=word2[j])
              { 
                  int u=word1[j]-'a';
                  int v=word2[j]-'a';
                 
                  adjList[u].push_back(v);
                  break;
              }
          }
      }
   
      vector<int> topo;
      toposort(adjList,topo,K);
      string ans;
      for(int i=0;i<topo.size();++i)
      {   char ch=topo[i]+'a';
          
          ans.push_back(ch);
      }
      //cout<<ans;
      return ans;
      
      
    }
};

//{ Driver Code Starts.
string order;
bool f(string a, string b) {
    int p1 = 0;
    int p2 = 0;
    for (int i = 0; i < min(a.size(), b.size()) and p1 == p2; i++) {
        p1 = order.find(a[i]);
        p2 = order.find(b[i]);
        //	cout<<p1<<" "<<p2<<endl;
    }

    if (p1 == p2 and a.size() != b.size()) return a.size() < b.size();

    return p1 < p2;
}

// Driver program to test above functions
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, K;
        cin >> N >> K;
        string dict[N];
        for (int i = 0; i < N; i++) cin >> dict[i];
        
        Solution obj;
        string ans = obj.findOrder(dict, N, K);
        order = "";
        for (int i = 0; i < ans.size(); i++) order += ans[i];

        string temp[N];
        std::copy(dict, dict + N, temp);
        sort(temp, temp + N, f);

        bool f = true;
        for (int i = 0; i < N; i++)
            if (dict[i] != temp[i]) f = false;

        if(f)cout << 1;
        else cout << 0;
        cout << endl;
    }
    return 0;
}

// } Driver Code Ends