//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

int LCSof3 (string A, string B, string C, int n1, int n2, int n3);
int main()
{
    int t; cin >> t;
    while (t--)
    {
        int n1, n2, n3; cin >> n1 >> n2 >> n3;
        string A, B, C; cin >> A >> B >> C;
        cout << LCSof3 (A, B, C, n1, n2, n3) << endl;
    }
}
// Contributed By: Pranay Bansal

// } Driver Code Ends

int solve(string& a,string& b,string& c,int& n1,int& n2,int& n3,int i,int j,int k, vector<vector<vector<int> > >& dp){
    
    if(i>=n1 || j>=n2 || k>=n3)
    {
        return 0;
    }
    if(dp[i][j][k]!=-1)
    {
        return dp[i][j][k];
    }
    //if all match
    int ans=0;
    if(a[i]==b[j] && a[i]==c[k] && b[j]==c[k])
    {
        ans=1+solve(a,b,c,n1,n2,n3,i+1,j+1,k+1,dp);
    }
    else{
        int op1=solve(a,b,c,n1,n2,n3,i+1,j,k,dp);
        int op2=solve(a,b,c,n1,n2,n3,i,j+1,k,dp);
        int op3=solve(a,b,c,n1,n2,n3,i,j,k+1,dp);
        
         ans=max(op1,max(op2,op3));
    }
    
    return dp[i][j][k]=ans;
}
int solvetab(string& a,string& b,string& c,int n1,int n2,int n3)
{
     vector<vector<vector<int> > > dp(n1+1, vector<vector<int> >(n2+1,vector<int>(n3+1,0)));
     for(int i=n1-1;i>=0;--i)
     {
         for(int j=n2-1;j>=0;--j)
         {
             for(int k=n3-1;k>=0;--k)
             {
                int ans=0;
                if(a[i]==b[j] && a[i]==c[k] && b[j]==c[k])
                {
                    ans=1+dp[i+1][j+1][k+1];
                }
                else{
                    int op1=dp[i+1][j][k];
                    int op2=dp[i][j+1][k];
                    int op3=dp[i][j][k+1];
                    
                    ans=max(op1,max(op2,op3));
                }
                
                dp[i][j][k]=ans;
             }
         }
     }
     return dp[0][0][0];
}
// int solve(string& a,string& b,string& c,int& n1,int& n2,int& n3,int i,int j,int k){
    
//     if(i>=n1 || j>=n2 || k>=n3)
//     {
//         return 0;
//     }
//     //if all match
//     int ans=0;
//     if(a[i]==b[j] && a[i]==c[k] && b[j]==c[k])
//     {
//         ans=1+solve(a,b,c,n1,n2,n3,i+1,j+1,k+1);
//     }
//     else{
//         int op1=solve(a,b,c,n1,n2,n3,i+1,j,k);
//         int op2=solve(a,b,c,n1,n2,n3,i,j+1,k);
//         int op3=solve(a,b,c,n1,n2,n3,i,j,k+1);
        
//         int ans=max(op1,max(op2,op3));
//     }
    
//     return ans;
// }
int LCSof3 (string A, string B, string C, int n1, int n2, int n3){
// {  vector<vector<vector<int> > > dp(n1, vector<vector<int> >(n2,vector<int>(n3,-1)));
//     return solve(A,B,C,n1,n2,n3,0,0,0,dp);
    return solvetab(A,B,C,n1,n2,n3);
}