#include <bits/stdc++.h>
int solve(vector<int>& a,int n,int k,int index,int prod,vector<vector<int> >& dp)
{
    if(index>=n && prod!=0 && prod<=k)
    {
        return 1;
    }
    if(index>=n )
    return 0;

    if(dp[index][prod]!=-1)
    {
        return dp[index][prod];
    }
    //in case of include.
    int incl=0;
    if(prod==0)
    {    if(prod+a[index]<=k)
         incl=solve(a,n,k,index+1,prod+a[index],dp);
    }
    else{ if(prod*a[index]<=k)
         incl=solve(a,n,k,index+1,prod*a[index],dp);
    }

    //in case of excl
    int excl=solve(a,n,k,index+1,prod,dp);

    return dp[index][prod]=(incl+excl);
} 
int bottomup(vector<int>& a,int n,int k)
{
    vector<vector<int> > dp(n+1,vector<int>(k+1,0));
    for(int prod=1;prod<=k;++k)
    {
        dp[n][prod]=1;
    }

    for(int index=n-1;index>=0;--index)
    {
        for(int prod=k;prod>=0;--prod)
        {
                int incl=0;
              
                if(prod*a[index]<=k)
                incl=dp[index+1][prod*a[index]];
               

                //in case of excl
                int excl=dp[index+1][prod];

                 dp[index][prod]=(incl+excl);
        }
    }
    return dp[0][0];
}
int countSubsequences(vector < int > & a, int n, int p) {
    int ans=0;
    // vector<vector<int> > dp(n,vector<int>(p+1,-1));
    // ans=solve(a,n,p,0,0,dp);
    ans=bottomup(a,n,p);
    return ans;
}