//{ Driver Code Starts
#include<bits/stdc++.h>
const int mod=1e9+7;
using namespace std;

// } Driver Code Ends
// function to find longest common subsequence

class Solution
{
    public:
    //Function to find the length of longest common subsequence in two strings.
    int solve(int l1,int l2,string& s1,string& s2,int i,int j,vector<vector<int> >& dp)
    {
        if(i>=l1 || j>=l2)
        {
            return 0;
        }
        if(dp[i][j]!=-1)
        {
            return dp[i][j];
        }
        //char ya to match honge ya ni honge 
        //agar match hote hai to.
        int ans=0;
        if(s1[i]==s2[j])
        {// 1 + kyu?? i know , you can ask me
            ans=1+solve(l1,l2,s1,s2,i+1,j+1,dp);
        }
        else{
            ans=max(solve(l1,l2,s1,s2,i,j+1,dp),solve(l1,l2,s1,s2,i+1,j,dp));
        }
        return dp[i][j]=ans;
    }
    int solvetab(int l1,int l2,string& s1,string& s2)
    {
       
        vector<int> current(l2+1,0);
        vector<int> temp(l2+1,0);
        for(int i=l1-1;i>=0;--i)
        {
            for(int j=l2-1;j>=0;--j)
            {
               int ans=0;
            if(s1[i]==s2[j])
            {// 1 + kyu?? i know , you can ask me
                ans=1+temp[j+1];
            }
            else{
                ans=max(current[j+1],temp[j]);
            }
             current[j]=ans;
            }
            temp=current;
        }
        return current[0];
    }
    // int solvetab(int l1,int l2,string& s1,string& s2)
    // {
    //     vector<vector<int> > dp(l1+1,vector<int>(l2+1,0));
        
    //     for(int i=l1-1;i>=0;--i)
    //     {
    //         for(int j=l2-1;j>=0;--j)
    //         {
    //           int ans=0;
    //         if(s1[i]==s2[j])
    //         {// 1 + kyu?? i know , you can ask me
    //             ans=1+dp[i+1][j+1];
    //         }
    //         else{
    //             ans=max(dp[i][j+1],dp[i+1][j]);
    //         }
    //          dp[i][j]=ans;
    //         }
    //     }
    //     return dp[0][0];
    // }
    int lcs(int x, int y, string s1, string s2)
   {
 // {  vector<vector<int> > dp(x,vector<int>(y,-1));
    //     return solve(x,y,s1,s2,0,0,dp);
        return solvetab(x,y,s1,s2);
    }
};


//{ Driver Code Starts.
int main()
{
    int t,n,k,x,y;
    cin>>t;
    while(t--)
    {
        cin>>x>>y;          // Take size of both the strings as input
        string s1,s2;
        cin>>s1>>s2;        // Take both the string as input
        Solution ob;
        cout << ob.lcs(x, y, s1, s2) << endl;
    }
    return 0;
}

// } Driver Code Ends