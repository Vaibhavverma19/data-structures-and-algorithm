#include <bits/stdc++.h> 
bool issafe(int row,int col,vector<vector<int> >& field)
{
	if(row<0 || row>=field.size() || col<0 || col>=field[0].size() || field[row][col]==0 || field[row][col]==2 || field[row][col]==10)
	{
		return false;
	}
	return true;
}
int solve(vector<vector<int>>& field,int row,int col,vector<vector<int>>& dp)
{
	if(col==field[0].size()-1)
	{  //cout<<"bc is returning for "<<row<<","<<col<<endl;
		// mini=min(mini,steps);
		return 0;
	}
    if(dp[row][col]<1e9+7)
	{
		//cout<<"dp is returning";
	return dp[row][col];
	}

	int ans=1e9+7;
	//right
	
	if(issafe(row,col+1,field))
	{
		field[row][col+1]=10;
		int r=1+solve(field,row,col+1,dp);
		ans=min(ans,r);
		field[row][col+1]=1;
	}
	//down
	
	if(issafe(row+1,col,field))
	{
		field[row+1][col]=10;
		int d=1+solve(field,row+1,col,dp);
		ans=min(ans,d);
		field[row+1][col]=1;
	}
	// //left
	
	// if(issafe(row,col-1,field))
	// {
	// 	field[row][col-1]=10;
	// 	int l=1+solve(field,row,col-1,dp);
	// 	ans=min(ans,l);
	// 	field[row][col-1]=1;
	// }
	//up
	
	if(issafe(row-1,col,field))
	{
		field[row-1][col]=10;
		int u=1+solve(field,row-1,col,dp);
		ans=min(ans,u);
		field[row-1][col]=1;
	}
    //cout<<"("<<row<<","<<col<<") dp is"<<ans<<endl;
	return dp[row][col]=ans;

}
int shortestPath(vector<vector<int>> &field)
{
	for(int row=0;row<field.size();++row)
	{
		for(int col=0;col<field[0].size();++col)
		{
			if(field[row][col]==0)
			{
				//up
				if(row-1>=0 && field[row-1][col]!=0)
				{
					field[row-1][col]=2;
				}
				//down
				if(row+1<field.size() && field[row+1][col]!=0)
				{
					field[row+1][col]=2;
				}
				//left
				if(col-1>=0 && field[row][col-1]!=0)
				{
					field[row][col-1]=2;
				}
				//right
				if(col+1<field[0].size() && field[row][col+1]!=0)
				{
					field[row][col+1]=2;
				}
			}
		}
	}

	int mini=INT_MAX;
	vector<vector<int> > dp(field.size(),vector<int>(field[0].size(),1e9+7));
    int minimum=1e9+7;
	for(int i=0;i<field.size();++i)
	{
		if(issafe(i,0,field))
		{   field[i][0]=10;
			dp[i][0]=solve(field,i,0,dp);
			field[i][0]=1;
            minimum=min(minimum,dp[i][0]);
			
		}
	}


	if(minimum>=1e9+7)
	return -1;

	return minimum;
}