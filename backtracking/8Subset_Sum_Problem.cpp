int solve(vector<int>& arr,int sum,int index, vector<vector<int> >& dp)
{
	if(index==arr.size())
	{
		return 0;
	}

	if(sum==0)
	{
		return 1;
	}
     
	if(dp[index][sum]!=-1)
	{
		return dp[index][sum];
	} 
	//include
	if(sum-arr[index]>=0)
	{
	int temp1=solve(arr,sum-arr[index],index+1,dp);
	if(temp1)
	{
		 return dp[index][sum]=temp1;
	}

	}

	//exclude
	int temp2=solve(arr,sum,index+1,dp);
	if(temp2)
	{ return dp[index][sum]=temp2;
	}
	
  return dp[index][sum]=0;
}
bool canPartition(vector<int> &arr, int n)
{   int sum=0;
	for(auto num:arr)
	{
		sum+=num;
	}

	if(sum&1)
	{
		//that is odd sum
		return false;
	}
    vector<vector<int> > dp(n+1,vector<int>(sum+1,-1));
	sum=sum/2;
	return solve(arr,sum,0,dp);
}
