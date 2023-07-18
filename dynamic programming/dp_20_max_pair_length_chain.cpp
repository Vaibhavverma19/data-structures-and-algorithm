//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct val{
	int first;
	int second;
};


// } Driver Code Ends
/*
The structure to use is as follows
struct val{
	int first;
	int second;
};*/

class Solution{
public:
  static bool comp(struct val A,struct val B)
  {
      return A.second<B.second;
  }
  int solve(struct val p[],int n,int curr,int prev,vector<vector<int> >& dp)
  {
      if(curr==n)
      return 0;
      if(dp[curr][prev+1]!=-1)
      {
          return dp[curr][prev+1];
      }
      int incl=0;
      if(prev==-1 || p[prev].second<p[curr].first)
      {
          incl=1+solve(p,n,curr+1,curr,dp);
      }
      
      int excl=solve(p,n,curr+1,prev,dp);
      
      return dp[curr][prev+1]=max(incl,excl); //prv+1 isiliye kuki prev -1 ki value prev 0 me store karayenge
  }
  
 int bottomup(struct val p[],int n)
 {
     //vector<vector<int> > dp(n+1,vector<int>(n+1,0));
     vector<int> curr_row(n+1,0);
     vector<int> next_row(n+1,0);
     for(int curr=n-1;curr>=0;--curr)
     {
         for(int prev=curr-1;prev>=-1;--prev)
         {
              int incl=0;
              if(prev==-1 || p[prev].second<p[curr].first)
              {
                  incl=1+next_row[curr+1];
              }
              
              int excl=next_row[prev+1];
              
             curr_row[prev+1]=max(incl,excl);
         }
         next_row=curr_row;
     }
     return curr_row[-1+1];
 }
    /*You are required to complete this method*/
    int maxChainLen(struct val p[],int n){
        int ans=0;
        sort(p,p+n,comp);
        // vector<vector<int> > dp(n,vector<int>(n+1,-1)); //+1 isiliye kuki prev avla -1 se nn-1 chalega to toal n indexes cover karega .
        
        // return solve(p,n,0,-1,dp);
        return bottomup(p,n);
    }
};

//{ Driver Code Starts.

int main() {
	// your code goes here
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		val p[n];
		for(int i=0;i<n;i++)
		{
			cin>>p[i].first>>p[i].second;
		}
		Solution ob;
		cout<<ob.maxChainLen(p,n)<<endl;
	}
	return 0;
}
// } Driver Code Ends