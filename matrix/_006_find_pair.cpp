#include <bits/stdc++.h> 
int findMaxValue(vector<vector<int>>& mat, int n) {
	vector<vector<int>> maxmat(n,vector<int>(n,INT_MIN));

	maxmat[n-1][n-1]=mat[n-1][n-1];

	//rightmost col
	for(int i=n-2;i>=0;--i)
	{
		if(mat[i][n-1]>maxmat[i+1][n-1])
		{
			maxmat[i][n-1]=mat[i][n-1];
		}else{
			maxmat[i][n-1]=maxmat[i+1][n-1];
		}
	}
	//lowermost row
	for(int i=n-2;i>=0;--i)
	{
		if(mat[n-1][i]>maxmat[n-1][i+1])
		{
			maxmat[n-1][i]=mat[n-1][i];
		}else{
			maxmat[n-1][i]=maxmat[n-1][i+1];
		}
	}
   int ans=INT_MIN;
	//for remaining pos
	for(int i=n-2;i>=0;--i)
	{
		for(int j=n-2;j>=0;--j)
		{
           maxmat[i][j]=max(mat[i][j],max(maxmat[i][j+1],maxmat[i+1][j]));
		   ans=max(ans,maxmat[i+1][j+1]-mat[i][j]);
		}
	}

	return ans;
}