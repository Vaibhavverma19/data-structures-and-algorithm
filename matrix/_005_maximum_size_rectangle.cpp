#include<bits/stdc++.h>
void findprevsmaller(vector<int>& height,vector<int>& prevsmaller)
{
	stack<int> st;
	st.push(-1);
	for(int i=0;i<height.size();++i)
	{
		while(!st.empty() && st.top()!=-1 && height[st.top()]>=height[i])
		{
			st.pop();
		}
        prevsmaller[i]=st.top();
		st.push(i);
	}
}
void findnextsmaller(vector<int>& height,vector<int>& nextsmaller)
{
	stack<int> st;
	st.push(height.size());
	for(int i=height.size()-1;i>=0;--i)
	{
		while(!st.empty() && st.top()!=height.size() && height[st.top()]>=height[i])
		{
			st.pop();
		}
        nextsmaller[i]=st.top();
		st.push(i);
	}
}
int findlargestarea(vector<int> height)
{
	vector<int> prevsmaller(height.size());
	vector<int> nextsmaller(height.size());
	findprevsmaller(height,prevsmaller);
	findnextsmaller(height,nextsmaller);
	int ans=0;
	for(int i=0;i<height.size();++i)
	{
		int l=height[i];
		int b=nextsmaller[i]-prevsmaller[i]-1;
		int area=l*b;
		ans=max(ans,area);
	}
	return ans;

}
int maximalAreaOfSubMatrixOfAll1(vector<vector<int>> &mat, int n, int m){
	vector<int> height(m,0);
	int ans=0;
	for(int i=0;i<n;++i)
	{
		for(int j=0;j<m;++j)
		{
		  if(mat[i][j]==1)
		  {
			  height[j]+=1;
		  }else{
			  height[j]=0;
		  }
		}
      ans=max(ans,findlargestarea(height));
	}
	return ans;

}