//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int solve(int n,int r, vector<vector<int> >& dp)
    {
     if(n<r)
       {
           return 0;
       }
       if(r==0 || r==n)
       {
           return 1;
       }
       int mod=1000000007;
       int ans=0;
       if(dp[n][r]!=-1)
       {
           return dp[n][r];
       }
       
     ans=(solve(n-1,r-1,dp)+solve(n-1,r,dp))%mod;
       
       
       return dp[n][r]=ans;   
    }
    int bottomup(int n,int r)
    {
        //create dp 
        vector<vector<int> > dp(n+1,vector<int>(n+1,0));
        for(int i=0;i<=n;++i)
        {  dp[i][0]=1;
           dp[i][i]=1;
        }
        int mod=1000000007;
       
       for(int i=1;i<=n;++i)
       {
           for(int j=1;j<=r;++j)
           { int ans=0;
             
               ans=(dp[i-1][j-1]+dp[i-1][j])%mod;
       
       
               dp[i][j]=ans;
           }
       }
        
        return dp[n][r];
        
    }
    int nCr(int n, int r){
       int ans=0;
       int x=0;
       if(n<r)
       {
           return 0;
       }
       if(r<n-r)
       {
           x=r;
       }else{
           x=n-r;
       }
    //   vector<vector<int> > dp(n+1,vector<int>(x+1,-1));
    //   ans=solve(n,x,dp);
       ans=bottomup(n,x);
       return ans;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n, r;
        cin>>n>>r;
        
        Solution ob;
        cout<<ob.nCr(n, r)<<endl;
    }
    return 0;
}
// } Driver Code Ends