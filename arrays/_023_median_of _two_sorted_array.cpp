double median(vector<int>& a, vector<int>& b) {
	int n1=a.size();
	int n2=b.size();
	if(n2>n1) return median(b,a);

	//perform bs on shorted array ,less tc
	int start=0;
	int end=n1-1;
    int totalLeft=(n1+n2+1)/2;
	while(start<=end)
	{
       	int mid1=start + (end-start)/2;
		int mid2=totalLeft-mid1;
		int r1=INT_MAX,r2=INT_MAX;

		if(mid1<n1) r1=a[mid1];
		if(mid2<n2) r2=b[mid2];
		int l1=INT_MIN;
		int l2=INT_MIN;
		if(mid1-1>=0) l1=a[mid1-1];
		if(mid2-1>=0) l2=b[mid2-1];
		//now we have r1,r2,l1,l2
		if(l1<=r2 && l2<=r1)
		{   if((n1 + n2) & 1)
		    {
				return max(l1,l2);
			}
			else{
				double ans=max(l1,l2) + min(r1,r2);
				return ans/2.0;
			}
		}else{
			if(l1>r2){
				end=mid1-1;
			}else{
                start=mid1+1;
			}
		}
	}
}