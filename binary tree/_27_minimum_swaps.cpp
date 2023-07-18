#include <bits/stdc++.h> 
void preToIn(vector<int>& inorder,int index,vector<int>& arr,int n)
{
	if(index>=n)
	return;

	preToIn(inorder,2*index+1,arr,n);
	inorder.push_back(arr[index]);
	preToIn(inorder,2*index+2,arr,n);
}
int minimumSwaps(vector<int>&arr, int n) {
	vector<int> inorder;
	int swaps=0;
	preToIn(inorder,0,arr,n);
    vector<pair<int,int> > v;
	for(int i=0;i<n;++i)
	{
		v.push_back({inorder[i],i});
	}
	sort(v.begin(),v.end());
	int ans=0;
	for(int i=0;i<n;++i)
	{
		int value=v[i].first;
		int index=v[i].second;

		if(i!=index)
		{   
			swaps++;
			swap(v[i],v[index]);
			i--;
		}
	}

	return swaps;
	
}