#include <bits/stdc++.h> 
void solve(string& s,vector<string>& ans,string& temp,unordered_map<int,bool>& vis,int n )
{
    if(temp.length()==n)
    {
        ans.push_back(temp);
        return;
    }

    for(int i=0;i<n;++i)
    {
        if(vis[i]!=true)
        {
            vis[i]=true;
            temp.push_back(s[i]);
            solve(s,ans,temp,vis,n);
            temp.pop_back();
            vis[i]=false;
        }
    }
}
vector<string> findPermutations(string &s) {
    string temp="";
    vector<string> ans;
    unordered_map<int,bool> vis;
    solve(s,ans,temp,vis,s.length());
    return ans;

}