//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;



// } Driver Code Ends
class Solution
{
    public:
    int solve(int target,int x,int y,int z,vector<int>& dp)
    {
        if(target==0)
        return 0;
        if(target<0)
        return INT_MIN;
        if(dp[target]!=-1)
        {
            return dp[target];
        }
        int op1=1+solve(target-x,x,y,z,dp);
        int op2=1+solve(target-y,x,y,z,dp);
        int op3=1+solve(target-z,x,y,z,dp);
        
        return dp[target]=max(op1,max(op2,op3));
    }
    int bottomup(int n,int x,int y,int z)
    {
        vector<int> dp(n+1,0);
        
        for(int target=0;target<=n;++target)
        {  int op1=INT_MIN,op2=INT_MIN,op3=INT_MIN;
            if(target>=x)
             op1=1+solve(target-x,x,y,z,dp);
            if(target>=y)
             op2=1+solve(target-y,x,y,z,dp);
            if(target>=z)
             op3=1+solve(target-z,x,y,z,dp);
            
            dp[target]=max(op1,max(op2,op3)); 
            }
        return dp[n];
    }
    //Function to find the maximum number of cuts.
    int maximizeTheCuts(int n, int x, int y, int z)
    {   if(n<x && n<y && n<z)
         {
             return 0;
         }
    //      vector<int> dp(n+1,-1);
    //   int ans= solve(n,x,y,z,dp);
       int ans= bottomup(n,x,y,z);
       if(ans<0)
       return 0;
       return ans;
    }
};

//{ Driver Code Starts.
int main() {
    
    //taking testcases
    int t;
    cin >> t;
    while(t--)
    {
        //taking length of line segment
        int n;
        cin >> n;
        
        //taking types of segments
        int x,y,z;
        cin>>x>>y>>z;
        Solution obj;
        //calling function maximizeTheCuts()
        cout<<obj.maximizeTheCuts(n,x,y,z)<<endl;

    }

	return 0;
}
// } Driver Code Ends