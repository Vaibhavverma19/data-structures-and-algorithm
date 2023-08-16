//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
	public:
	
	    void solve(string& s,set<string>& ans,string& tempAns,unordered_map<int,bool>& vis)
	    {  if(tempAns.length()==s.length())
	        {
	            ans.insert(tempAns);
	            return;
	        }
	        for(int i=0;i<s.length();i++)
	        {
	            if(vis[i]!=true)
	            {
	                vis[i]=true;
	                tempAns+=s[i];
	                solve(s,ans,tempAns,vis);
	                vis[i]=false;
	                tempAns.pop_back();
	            }
	        }
	    }
		vector<string>find_permutation(string S)
		{
		    set<string> ans;
		    string tempAns;
		    unordered_map<int,bool> vis;
		    solve(S,ans,tempAns,vis);
		    vector<string> answer;
		    for(auto perm:ans)
		    {
		        answer.push_back(perm);
		    }
		    return answer;
		    
		}
};



//{ Driver Code Starts.
int main(){
    int t;
    cin >> t;
    while(t--)
    {
	    string S;
	    cin >> S;
	    Solution ob;
	    vector<string> ans = ob.find_permutation(S);
	    sort(ans.begin(),ans.end());
	    for(auto i: ans)
	    {
	    	cout<<i<<" ";
	    }
	    cout<<"\n";
    }
	return 0;
}

// } Driver Code Ends