#include <bits/stdc++.h> 
int solve(string& str1,string& str2,int i,int j,vector<vector<int> >& dp)
{
  if(i==str1.length() || j==str2.length())
  {
    return 0;
  }
  if(dp[i][j]!=-1)
  {
    return dp[i][j];
  }
  //if character match but their index should be different tbhi to hm nikal paynge ki yhi string puri 
  //dobara same characters ke sath present hai ki ni.
  int ans=0;
  if(str1[i]==str2[j]  && i!=j)
  {
    ans=1+solve(str1,str2,i+1,j+1,dp);
  }
  else{
    int op1=solve(str1,str2,i,j+1,dp);
    int op2=solve(str1,str2,i+1,j,dp);
    ans=max(op1,op2);
  }

  return dp[i][j]=ans;
}

// // dp+tabulation
// int solve(string& str1,string& str2)
// {
//   vector<vector<int> > dp(str1.length()+1,vector<int>(str1.length()+1,0));
  
//   for(int i=str1.length()-1;i>=0;--i)
//   {
//     for(int j=str2.length()-1;j>=0;--j)
//     {
//         if(str1[i]==str2[j]  && i!=j)
//         {
//           dp[i][j]=1+dp[i+1][j+1];
//         }
//         else{
//           int op1=dp[i][j+1];
//           int op2=dp[i+1][j];
//           dp[i][j]=max(op1,op2);
//         }
//     }
//   }

//   return dp[0][0];
// }
int LRS(string & str) {

  vector<vector<int> > dp(str.length()+1,vector<int>(str.length()+1,-1));
   return solve(str,str,0,0,dp);

  // return solve(str,str);
}