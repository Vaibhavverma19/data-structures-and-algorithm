//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution
{
    public:
    int solve(int n,int a[],int curr,int prev,vector<vector<int> >& dp)
    {
        if(curr==n)
        return 0;
        
        int incl=0,excl=0;
        if( dp[curr][prev+1]!=-1)
        {
            return dp[curr][prev+1];
        }
        
        if(prev==-1 || a[curr]>a[prev])
        {
            incl=1+solve(n,a,curr+1,curr,dp);
        }
        
        excl=solve(n,a,curr+1,prev,dp);
        
        return dp[curr][prev+1]=max(incl,excl);
        
    }
    int solvetab(int n,int a[])
    {
        vector<vector<int> > dp(n+1,vector<int>(n+1,0));
        
        for(int curr=n-1;curr>=0;--curr)
        {
            for(int prev=n-1;prev>=-1;--prev)
            {  int incl=0;
              if(prev==-1 || a[curr]>a[prev])
                {
                    incl=1+dp[curr+1][curr+1];
                }
                
               int excl=dp[curr+1][prev+1];
                
                 dp[curr][prev+1]=max(incl,excl);
            }
        }
        return dp[0][0];
    }
    //Function to find length of longest increasing subsequence.
    int longestSubsequence(int n, int a[])
   { // { vector<vector<int> > dp(n,vector<int>(n+1,-1));
    //   return solve(n,a,0,-1,dp);
      return solvetab(n,a);
    }
};

//{ Driver Code Starts.
int main()
{
    //taking total testcases
    int t,n;
    cin>>t;
    while(t--)
    {
        //taking size of array
        cin>>n;
        int a[n];
        
        //inserting elements to the array
        for(int i=0;i<n;i++)
            cin>>a[i];
        Solution ob;
        //calling method longestSubsequence()
        cout << ob.longestSubsequence(n, a) << endl;
    }
}

// } Driver Code Ends