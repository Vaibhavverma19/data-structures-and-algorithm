//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++


class Solution{
  public:
  int solve(vector<int>& a,int prev2,int prev1,int curr,vector<vector<vector<int> > >& dp)
  {
      if(curr==a.size())
      {
          return 0;
      }
      if(dp[curr][prev1+1][prev2+2]!=-1)
      {
          return dp[curr][prev1+1][prev2+2];
      }
      int incl=0;
      //include if its not third cnsecutive.
      if(curr==0 ||curr==1 || (curr-prev1!=1) || (curr-prev1==1 && prev1-prev2!=1))
      {
          incl=a[curr]+solve(a,prev1,curr,curr+1,dp);
      }
      
      int excl=solve(a,prev2,prev1,curr+1,dp);
      
      return dp[curr][prev1+1][prev2+2]= max(incl,excl);
  }
  int findMaxSum(vector<int>& a){
      int ans=0;
      int x=a.size();
      vector<vector<vector<int> > > dp(x,vector<vector<int> >(x,vector<int>(x,-1)));
      ans=solve(a,-2,-1,0,dp);
      return ans;
  }
};

//{ Driver Code Starts.



int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> a(n);
        for(int i=0;i<n;i++){
            cin>>a[i];
        }
        
        Solution ob;
        int ans = ob.findMaxSum(a);
        cout<<ans<<endl;
    }
}
// } Driver Code Ends