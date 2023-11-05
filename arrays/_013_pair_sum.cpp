#include <bits/stdc++.h> 
int pairSum(vector<int> &arr, int n, int target){
int i=0;
int j=n-1;
int ans=0;
while(i<j){
	if(arr[i]+arr[j]==target)
	{
		ans++;
		i++;
		j--;
	}else{
		if(arr[i]+arr[j]>target)
		{
			j--;
		}else{
			i++;
		}
	}
}

return ans==0?-1:ans;
}