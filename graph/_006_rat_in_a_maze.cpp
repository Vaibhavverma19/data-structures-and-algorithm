//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution{
    public:
    void solve(vector<vector<int>> &m, int& n,int i,int j,map<pair<int,int>,bool>& vis,vector<string>& ans,string str)
    {
        
        if((i<0 || i>n-1) || (j<0 || j>n-1))
        {
            return;
        }
        
        if(m[i][j]!=1)
        return;
        
        
        
        if(i==n-1 && j==n-1)
        {
            ans.push_back(str);
        }
        vis[{i,j}]=true;
        //left
        if(vis[{i,j-1}]!=true )
        {   str.push_back('L');
            solve(m,n,i,j-1,vis,ans,str);
            str.pop_back();
        }
        //right
        if(vis[{i,j+1}]!=true)
        {   str.push_back('R');
            solve(m,n,i,j+1,vis,ans,str);
            str.pop_back();
        }
        //down
        if(vis[{i+1,j}]!=true)
        {   str.push_back('D');
            solve(m,n,i+1,j,vis,ans,str);
            str.pop_back();
        }
        //up
        if(vis[{i-1,j}]!=true)
        {   str.push_back('U');
            solve(m,n,i-1,j,vis,ans,str);
            str.pop_back();
        }
        
         vis[{i,j}]=false;
    }
    vector<string> findPath(vector<vector<int>> &m, int n) {
        map<pair<int,int>,bool> vis;
        vector<string> ans;
        string str;
        solve(m,n,0,0,vis,ans,str);
        return ans;
        
        
    }
};

    


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> m(n, vector<int> (n,0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> m[i][j];
            }
        }
        Solution obj;
        vector<string> result = obj.findPath(m, n);
        sort(result.begin(), result.end());
        if (result.size() == 0)
            cout << -1;
        else
            for (int i = 0; i < result.size(); i++) cout << result[i] << " ";
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends