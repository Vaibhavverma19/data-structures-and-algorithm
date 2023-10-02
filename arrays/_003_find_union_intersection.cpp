#include <bits/stdc++.h> 
pair < int , int > findSimilarity(vector < int > arr1, vector < int > arr2, int n, int m) 
{   sort(arr1.begin(),arr1.end());
	  sort(arr2.begin(),arr2.end());
	int p1=0;
	int p2=0;
	int cnt_same=0;
	while(p1!=n && p2!=m)
	{
		if(arr1[p1]==arr2[p2])
		{
			cnt_same++;
			p1++;
			p2++;
		}else{
			if(arr1[p1]<arr2[p2])
			{
				p1++;
			}else{
				p2++;
			}
		}
	}  
	int uni=n+m-cnt_same;
	return {cnt_same,uni};     
}