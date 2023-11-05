#include <bits/stdc++.h> 
vector<double> findMedian(vector<int> &arr, int n, int m)
{
	vector<double> ans;
	int k=0;
	int j=m-1;
	vector<int> temp(m);
	
	while(j<n)
	{   for(int i=0;i<m;++i)
		{
			temp[i]=arr[i+k];
		}
		sort(temp.begin(),temp.end());
		if(m & 1){
			int mid=m/2;
			double median=temp[mid];
			ans.push_back(median);
		}else{
			int mid=(m-1)/2;
			double median=(temp[mid]+temp[mid+1])/2.0;
			ans.push_back(median);
		}
		k++;
        j++;
	}

	return ans;
}