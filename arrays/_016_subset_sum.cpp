#include <bits/stdc++.h> 
int  solve(int n,int target,vector<int>& arr,int index,vector<vector<int> >& dp)
{   //cout<<"target left "<<target<<endl;
    if(target==0)
    {   //cout<<"yes";
        return 1;
    }
    if(index==n)
    { //cout<<"returning coz "<<index<<endl;
        return -1;
    }
    if(dp[index][target]!=0)
    {  //cout<<"i m culprit"<<endl;
        return dp[index][target];
    }

    for(int i=index;i<n;++i)
    { // cout<<"iii"<<endl;
        if(arr[i]<=target)
        { //cout<<"inside loop "<<endl;
            int ans=solve(n,target-arr[i],arr,i+1,dp);
            if(ans==1)
            return dp[index][target]=ans;
        }
    }

    return dp[index][target]=-1;
}
bool subsetSumToK(int n, int k, vector<int> &arr) {
    vector<vector<int> > dp(n+1,vector<int>(k+1,0));
     int ans=solve(n,k,arr,0,dp);
    return dp[0][k]==1?true:false;
}