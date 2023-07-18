//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int solve(int arr[],int i,int j, vector<vector<int> >& dp)
    {
        //base case
        //1. ya to starting index ending index ke aage nikal jaye mtlb subpart empty ho.
        //2. ya ek hi element ho subpart me. ek matrix ki khud se multiplication ni hogi isme.
        if(i>=j)
        {
            return 0;
        }
        if(dp[i][j]!=-1)
        {
            return dp[i][j];
        }
        int mini=INT_MAX;
        int ans=0;
        for(int k=i;k<j;++k)
        {
            ans=solve(arr,i,k,dp)+solve(arr,k+1,j,dp)+arr[i-1]*arr[k]*arr[j];
            mini=min(mini,ans);
        }
        return dp[i][j]=mini;
    }
    int solvetab(int arr[],int n)
    {
       vector<vector<int> > dp(n,vector<int>(n,0));
       for(int i=n-1;i>=1;--i)
       {
           for(int j=1;j<n;++j)
           {
             int mini=INT_MAX;
             int ans=0;
             for(int k=i;k<j;++k)
             {
                ans=dp[i][k]+dp[k+1][j]+arr[i-1]*arr[k]*arr[j];
                mini=min(mini,ans);
                 dp[i][j]=mini;
             }
            
           }
       }
       return dp[1][n-1];
    }
    int matrixMultiplication(int N, int arr[])
    {
       int ans=0;
    //   vector<vector<int> > dp(N,vector<int>(N,-1));
    //   ans=solve(arr,1,N-1,dp);
       ans=solvetab(arr,N);
       return ans;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int arr[N];
        for(int i = 0;i < N;i++)
            cin>>arr[i];
        
        Solution ob;
        cout<<ob.matrixMultiplication(N, arr)<<endl;
    }
    return 0;
}
// } Driver Code Endschrome-extension://mcgbeeipkmelnpldkobichboakdfaeon/images/logo-vertical.svg