#include <bits/stdc++.h>
long solve(int n,int k)
{
	// vector<vector<long> > dp(n+1,vector<long>(n+1,0));
	// for(int i=0;i<=n;++i)
	// {
	// 	dp[i][0]=1;
	// }

	vector<long> curr(n+1,0);
	vector<long> prev(n+1,0);
	curr[0]=1;
	prev[0]=1;
	 int mod=1000000007;
	for(int i=1;i<=n;++i)
	{
		for(int j=1;j<=k;++j)
		{
			curr[j]=i*prev[j-1]%mod;
		}

		prev=curr;
	}
   
	return curr[k];
} 
int P(int n, int k) {

	int ans=0;
	if(n<k)
	{
		return 0;
	}
	ans=solve(n,k);
	return ans;

	

}