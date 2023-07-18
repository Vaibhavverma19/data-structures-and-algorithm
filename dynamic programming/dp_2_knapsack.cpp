//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    //Function to return max value that can be put in knapsack of capacity W.
    int solve(int current_weight,int current_item,int wt[],int val[],int n,vector<vector<int> >& dp)
    {
        if(current_weight==0)
        {
            return 0;
        }
        if(current_item>=n)
        {
            return 0;
        }
        if(dp[current_item][current_weight]!=-1)
        {
            return dp[current_item][current_weight];
        }
        int incl=0;
        if(current_weight>=wt[current_item])
         incl=val[current_item]+solve(current_weight-wt[current_item],current_item+1,wt,val,n,dp);
        
        int excl=solve(current_weight,current_item+1,wt,val,n,dp);
        
        return dp[current_item][current_weight]=max(incl,excl);
        
    }
    int bottomup(int W,int wt[],int val[],int n)
    {
        //create dp.
       vector<vector<int> > dp(n+1,vector<int>(W+1,0));
       
       for(int current_item=n-1;current_item>=0;--current_item)
       {
           for(int current_weight=1;current_weight<=W;++current_weight)
           {
               int incl=0;
               if(current_weight>=wt[current_item])
               incl=val[current_item]+dp[current_item+1][current_weight-wt[current_item]];
        
               int excl=dp[current_item+1][current_weight];
        
               dp[current_item][current_weight]=max(incl,excl);
           }
       }
       return dp[0][W];
    }
    int knapSack(int W, int wt[], int val[], int n) 
    { 
       int ans=0;
       //create dp.
    //   vector<vector<int> > dp(n,vector<int>(W+1,-1));
    //   ans=solve(W,0,wt,val,n,dp);
       ans=bottomup(W,wt,val,n);
       return ans;
    }
};

//{ Driver Code Starts.

int main()
 {
    //taking total testcases
    int t;
    cin>>t;
    while(t--)
    {
        //reading number of elements and weight
        int n, w;
        cin>>n>>w;
        
        int val[n];
        int wt[n];
        
        //inserting the values
        for(int i=0;i<n;i++)
            cin>>val[i];
        
        //inserting the weights
        for(int i=0;i<n;i++)
            cin>>wt[i];
        Solution ob;
        //calling method knapSack()
        cout<<ob.knapSack(w, wt, val, n)<<endl;
        
    }
	return 0;
}
// } Driver Code Ends