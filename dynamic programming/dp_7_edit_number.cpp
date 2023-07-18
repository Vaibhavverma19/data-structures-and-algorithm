//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
  int solve(string& str1,string& str2,int i,int j, vector<vector<int> >& dp)
  {
      if(i==str1.length() && j==str2.length())
      {
          return 0;
      }
      if(i==str1.length())
      {
          return str2.length()-j;
      }
      if(j==str2.length())
      {
          return str1.length()-i;
      }
      if(dp[i][j]!=-1)
      {
          return dp[i][j];
      }
      if(str1[i]==str2[j])
      {
          return dp[i][j]=solve(str1,str2,i+1,j+1,dp);
      }
      else{
          int del=solve(str1,str2,i,j+1,dp);
          int rep=solve(str1,str2,i+1,j+1,dp);
          int ins=solve(str1,str2,i+1,j,dp);
          return dp[i][j]=1+min(del,min(rep,ins));
      }
  }
  int solvetab(string& str1,string& str2)
  {
      //create dp.
      vector<vector<int> > dp(str1.length()+1,vector<int>(str2.length()+1,0));
      
      //handle base cases.
      for(int i=0;i<str1.length();++i)
      {
          dp[i][str2.length()]=str1.length()-i;
      }
      for(int j=0;j<str2.length();++j)
      {
          dp[str1.length()][j]=str2.length()-j;
      }
      
      for(int i=str1.length()-1;i>=0;--i)
      {
          for(int j=str2.length()-1;j>=0;--j)
          {
              if(str1[i]==str2[j])
              {
                 dp[i][j]=dp[i+1][j+1];
               }
              else{
                   int del=dp[i][j+1];
                   int rep=dp[i+1][j+1];
                   int ins=dp[i+1][j];
                   dp[i][j]=1+min(del,min(rep,ins));
                   }
          }
      }
      return dp[0][0];
  }
    int editDistance(string s, string t) {
    //     vector<vector<int> > dp(s.length(),vector<int>(t.length(),-1));
    //   int ans=solve(s,t,0,0,dp);
       int ans=solvetab(s,t);
       return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int T;
    cin >> T;
    while (T--) {
        string s, t;
        cin >> s >> t;
        Solution ob;
        int ans = ob.editDistance(s, t);
        cout << ans << "\n";
    }
    return 0;
}

// } Driver Code Ends