//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int solve(int n,int m,vector<vector<int>>& M,int i,int j,vector<vector<int> >& dp)
    {
        if(i>=n || j>=m || i<0)
        {
            return 0;
        }
        if(dp[i][j]!=-1)
        {
            return dp[i][j];
        }
        int op1=M[i][j]+solve(n,m,M,i-1,j+1,dp);
        int op2=M[i][j]+solve(n,m,M,i,j+1,dp);
        int op3=M[i][j]+solve(n,m,M,i+1,j+1,dp);
        
        return dp[i][j]=max(op1,max(op2,op3));
    }
    int maxGold(int n, int m, vector<vector<int>> M)
    {  vector<vector<int> > dp(n,vector<int>(m,-1));
       int ans=INT_MIN;
       for(int i=0;i<n;++i)
       {
           for(int j=0;j<m;++j)
           {
               ans=max(ans,solve(n,m,M,i,j,dp));
           }
       }
       return ans;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n, m;
        cin>>n>>m;
        vector<vector<int>> M(n, vector<int>(m, 0));
        for(int i = 0;i < n;i++){
            for(int j = 0;j < m;j++)
                cin>>M[i][j];
        }
        
        Solution ob;
        cout<<ob.maxGold(n, m, M)<<"\n";
    }
    return 0;
}
// } Driver Code Ends