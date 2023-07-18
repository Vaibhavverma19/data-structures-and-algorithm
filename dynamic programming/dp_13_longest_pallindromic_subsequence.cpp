//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
  public:
    int solve(int l1,int l2,string& s1,string& s2,int i,int j)
    {
        if(i>=l1 || j>=l2)
        {
            return 0;
        }
        // if(dp[i][j]!=-1)
        // {
        //     return dp[i][j];
        // }
        //char ya to match honge ya ni honge 
        //agar match hote hai to.
        int ans=0;
        if(s1[i]==s2[j])
        {// 1 + kyu?? i know , you can ask me
            ans=1+solve(l1,l2,s1,s2,i+1,j+1);
        }
        else{
            
            ans=max(solve(l1,l2,s1,s2,i,j+1),solve(l1,l2,s1,s2,i+1,j));
        }
        return ans;
    }
    int longestPalinSubseq(string A) {
         string B=A;
        reverse(B.begin(),B.end());
        return solve(A.length(),B.length(),A,B,0,0);
    }
};

//{ Driver Code Starts.

int32_t main()
{
    int t; cin >> t;
    while (t--)
    {
        string s; cin >> s;
        Solution ob;
        cout << ob.longestPalinSubseq(s) << endl;
    }
}
// Contributed By: Pranay Bansal

// } Driver Code Ends