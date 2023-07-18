#include<vector>
long solve(int * denominations, int index, int n, int target,vector<vector<long> >& dp)
{
    if(target==0)
    {
        
        return 1;
    }
    if(target<0)
    {
        return 0;
    }
    if(dp[index][target]!=-1)
    {
        return dp[index][target];
    }
    long ans = 0;
    for(int i=index;i<n;++i)
    {
        ans += solve(denominations, i, n, target - denominations[i],dp);
        
    }

    return dp[index][target]=ans;
}
long bottomup(int *denominations,int n,int value)
{
    //create dp.
     vector<vector<long> > dp(n,vector<long>(value+1,0));
    //handle base case.
    for(int i=0;i<n;++i)
    {
        dp[i][0]=1;
    }
    //dekho loops kaha se kaha chalane hai.
    for(int index=n-1;index>=0;--index)
    {
        for(int target=1;target<=value;++target)
        {
             long ans = 0;
             for(int i=index;i<n;++i)
            { if(target-denominations[i]>=0)
              ans += dp[i][target-denominations[i]];
        
             }

           dp[index][target]=ans; 
        }
    }

}
long countWaysToMakeChange(int *denominations, int n, int value)
{
    long answer = 0;  
    vector<vector<long> > dp(n,vector<long>(value+1,-1));  
    answer=solve(denominations,0,n,value,dp);
    return answer;
}