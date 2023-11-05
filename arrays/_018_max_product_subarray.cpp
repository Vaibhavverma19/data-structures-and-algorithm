#include <bits/stdc++.h> 
int maximumProduct(vector<int> &arr, int n)
{
	int prefix=1;
	int suffix=1;
	int ans=INT_MIN;
	for(int i=0;i<n;++i)
	{   

		
		prefix*=arr[i];
		suffix*=arr[n-i-1];
		
		ans=max(ans,max(prefix,suffix));

		if(arr[i]==0)
		{
			prefix=1;
		}
		if(arr[n-i-1]==0)
		{
			suffix=1;
		}
	}

	return ans;
}
