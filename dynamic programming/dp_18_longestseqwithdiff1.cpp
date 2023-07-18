//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int solve(int n,int a[],int index,int prev)
    {
        if(index==n)
        return 0;
        int incl=0;
        //include if diff between prev and curr is 1
        if(prev==-1 || abs(prev-a[index])==1)
        {
            incl=1+solve(n,a,index+1,a[index]);
        }
        
        int excl=solve(n,a,index+1,prev);
        
        return max(incl,excl);
    }
    int longestSubsequence(int N, int A[])
    {
       int ans=solve(N,A,0,-1);
       return ans;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int A[N];
        for(int i = 0;i < N;i++)
            cin>>A[i];
        
        Solution ob;
        cout<<ob.longestSubsequence(N, A)<<endl;
    }
    return 0;
}
// } Driver Code Ends