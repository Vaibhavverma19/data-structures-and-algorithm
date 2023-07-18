//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
		

	public:
	int solve(int arr[],int n,int curr,int prev,vector<vector<int> >& dp)
	{
	    if(curr==n)
	    {
	        return 0;
	        
	    }
	    if(dp[curr][prev+1]!=-1)
	    {
	        return dp[curr][prev+1]; //prev+1 isiliye kuki prev -1 se n-1 chlega to hm use -1 ki jagah 0 vale index k me store kar lenge
	        
	    }
	    int incl=0;
	    if(prev==-1 || arr[curr]>arr[prev])
	    {
	        incl=arr[curr]+solve(arr,n,curr+1,curr,dp);
	        
	    }
	    
	    int excl=solve(arr,n,curr+1,prev,dp);
	    
	    return dp[curr][prev+1]=max(incl,excl);
	}
	int solvetab(int arr[],int n)
	{
	    vector<vector<int> > dp(n+1,vector<int>(n+1,0));
	    
	    for(int curr=n-1;curr>=0;--curr)
	    {
	        for(int prev=curr-1;prev>=-1;--prev)
	        {  int incl=0;
        	   if(prev==-1 || arr[curr]>arr[prev])
        	    {
        	        incl=arr[curr]+dp[curr+1][curr+1]; //curr+1 isiliye kuki dp me prev ka index originl se ek aage chal raha hai.
        	        
        	        
        	    }
        	    
        	    int excl=dp[curr+1][prev+1];
        	    
        	    dp[curr][prev+1]=max(incl,excl);
	        }
	    }
	    return dp[0][-1+1];
	}
	int maxSumIS(int arr[], int n)  {
// 	{   vector<vector<int> > dp(n,vector<int>(n+1,-1));  //prev ke liye n+1 kuki prev -1 se n-1 tk jayega 
// 	   //to total n+1 indexes ho gyi.
// 	    return solve(arr,n,0,-1,dp);
	    return solvetab(arr,n);
	}  
};

//{ Driver Code Starts.
int main() 
{
   	
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        int a[n];

        for(int i = 0; i < n; i++)
        	cin >> a[i];

      

	    Solution ob;
	    cout << ob.maxSumIS(a, n) << "\n";
	     
    }
    return 0;
}


// } Driver Code Ends