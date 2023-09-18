#include <bits/stdc++.h> 
int findsetbit(int n)
{ int cnt=0;
	while(n!=0)
	{
		if(n & 1)
		{
			return cnt;
		}else{
			cnt+=1;
			n=n>>1;
		}
	}

	return -1;
}
vector<int> findNonRepeating(vector<int> a)
{
	int XOR=a[0];
	for(int i=1;i<a.size();++i)
	{
		XOR =XOR^a[i];
	}

	int cnt=findsetbit(XOR);\
	//cout<<"cnt: "<<cnt<<endl;
    int rightsetbit=1;
	rightsetbit=rightsetbit<<cnt;
	int x=0,y=0;
	for(int i=0;i<a.size();++i)
	{
		if(a[i] & rightsetbit)
		{
			x=x^a[i];
		}else{
			y=y^a[i];
		}
	}

	vector<int> ans;
	ans.push_back(x);
	ans.push_back(y);

	return ans;
}
