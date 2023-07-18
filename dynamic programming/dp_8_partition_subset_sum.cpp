//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int solve(int arr[],int n,int target,int index,vector<vector<int> >& dp)
    {   
        if(target==0)
        {
            return 1;
        }
        if(target<0)
        {
            return 0;
        }
        if(index>=n)
        {
           return 0; 
        }
        
        if(dp[index][target]!=-1)
        {
            return dp[index][target];
        }
        
        int incl=solve(arr,n,target-arr[index],index+1,dp);
        
        int excl=solve(arr,n,target,index+1,dp);
        
        return dp[index][target]=max(incl,excl);
    }
    int equalPartition(int N, int arr[])
    {
       int sum=0;
       for(int i=0;i<N;++i)
       {
           sum+=arr[i];
       }
       if(sum&1==1)
       {
           return 0;
       }
       int target=sum/2;
       vector<vector<int> > dp(N,vector<int>(target+1,-1));
       return solve(arr,N,target,0,dp);
    }
};


//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int arr[N];
        for(int i = 0;i < N;i++)
            cin>>arr[i];
        
        Solution ob;
        if(ob.equalPartition(N, arr))
            cout<<"YES\n";
        else
            cout<<"NO\n";
    }
    return 0;
}
// } Driver Code Ends