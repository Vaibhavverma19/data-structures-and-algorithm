#include <bits/stdc++.h> 

bool issafe(int col,int row,vector<bool>& viscol,vector<bool>& visdiag1,vector<bool>& visdiag,int n)
{
if( viscol[col]==true || visdiag1[col-row +n-1]==true || visdiag[row+col]==true)
	{
		return false;
	}

	return true;
}
void solve(int n,vector<vector<int> >& ans,vector<int>& temp,vector<bool>& viscol,vector<bool>& visdiag1,vector<bool>& visdiag,int row)
{
    if(row==n)
	{
      ans.push_back(temp);
	  return;
	}
	for(int i=0;i<n;++i)
	{
       if(issafe(i,row,viscol,visdiag1,visdiag,n))
	   {
		   viscol[i]=true;
		   
		   visdiag1[i-row+n-1]=true;
		   visdiag[i+row]=true;
		   temp[row*n+i]=1;

		   solve(n,ans,temp,viscol,visdiag1,visdiag,row+1);

		   viscol[i]=false;
		   
		   visdiag1[i-row+n-1]=false;
		   visdiag[i+row]=false;
		   temp[row*n+i]=0;
	   }
	}

}
vector<vector<int>> nQueens(int n)
{
	vector<vector<int> > ans;
    vector<bool> visdiag1(n+n,false);
    vector<bool> viscol(n,false);
	int k=n+n;
    vector<bool> visdiag(k,false);
	int m=n*n;
	vector<int> temp(m,0);
	solve(n,ans,temp,viscol,visdiag1,visdiag,0);
	return ans;
	
}