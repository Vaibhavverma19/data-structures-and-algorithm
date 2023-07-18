//intuition very important........................
//{ Driver Code Starts
#include <bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
class Solution
{
public:
    int solve(int n,vector<int> dp)
    {
        if(n<=1)
        {
            return 1;
        }
        if(dp[n]!=-1)
        {
            return dp[n];
        }
        int ans=solve(n-1,dp)+ (n-1)*solve(n-2,dp);
        
        return dp[n]=ans%1000000007;
    }
    int solvetab(int n)
    {
        vector<long long> dp(n+1,0);
        dp[0]=1;
        dp[1]=1;
        for(int i=2;i<=n;++i)
        {
            dp[i]=dp[i-1]%1000000007+((i-1)*dp[i-2]%1000000007)%1000000007;
           
        }
        return dp[n]%1000000007;
    }
    int countFriendsPairings(int n) 
    {   
        // vector<int> dp(n+1,-1);
        // return solve(n,dp);
        return solvetab(n);
    }
};    
 

//{ Driver Code Starts.
int main() 
{
    int t;
    cin>>t;
    while(t--)
    {
    	int n;
    	cin>>n;
    	Solution ob;
    	cout <<ob.countFriendsPairings(n); 
    	cout<<endl;
    }
} 

// } Driver Code Ends