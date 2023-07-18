//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
int solve(int n,int m,vector<vector<int>>& mat,int& maxi,int r,int c,vector<vector<int>>& dp)
{
    if(r>=n || c>=m)
    return 0;
    if(dp[r][c]!=-1)
    return dp[r][c];
    
    int right=solve(n,m,mat,maxi,r,c+1,dp);
    int down=solve(n,m,mat,maxi,r+1,c,dp);
    int diag=solve(n,m,mat,maxi,r+1,c+1,dp);
    
    if(mat[r][c]==1)
    {  int ans=1+min(right,min(down,diag));
        maxi=max(maxi,ans);
        return dp[r][c]=ans;
    }
    else{
        return dp[r][c]=0;
    }
}
int solvetab(int n,int m,vector<vector<int>>& mat,int& maxi)
{
    vector<vector<int>> dp(n+1,vector<int>(m+1,0));
    
    for(int r=n-1;r>=0;--r)
    {
        for(int c=m-1;c>=0;--c)
        {
            int right=dp[r][c+1]; 
            int down=dp[r+1][c]; 
            int diag=dp[r+1][c+1];
            
            if(mat[r][c]==1)
            {  int ans=1+min(right,min(down,diag));
                maxi=max(maxi,ans);
                dp[r][c]=ans;
            }
            else{
               dp[r][c]=0;
            }
        }
    }
    return dp[0][0];
}
    int maxSquare(int n, int m, vector<vector<int>> mat){
        int maxi=0;
        // vector<vector<int>> dp(n,vector<int>(m,-1));
        // solve(n,m,mat,maxi,0,0,dp);
        solvetab(n,m,mat,maxi);
        return maxi;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n, m;
        cin>>n>>m;
        vector<vector<int>> mat(n, vector<int>(m, 0));
        for(int i = 0;i < n*m;i++)
            cin>>mat[i/m][i%m];
        
        Solution ob;
        cout<<ob.maxSquare(n, m, mat)<<"\n";
    }
    return 0;
}
// } Driver Code Ends