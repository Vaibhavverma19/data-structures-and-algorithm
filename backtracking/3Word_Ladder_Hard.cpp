#include <bits/stdc++.h> 
//overall tc o(n*(n-1)*d).
bool isInDict(string word,vector<string> &dictionary)
{   //o(n) but if we use unordered set for dict then o(1)
    for(auto temp:dictionary)
    {
        if(temp==word)
        {
            return true;
        }
    }
    return false;
}
void solve(string& s, vector<string> &dictionary,vector<string>& ans,string& ansString,int n,int pos)
{
    if(pos==n)
    {
        ans.push_back(ansString);
    }
    string word="";
    for(int i=pos;i<n;++i)
    {
        word.push_back(s[i]);
        if(isInDict(word,dictionary))
        {   string temp=ansString;
            ansString+=word;
            ansString.push_back(' ');
            solve(s,dictionary,ans,ansString,n,i+1);
            ansString=temp;
        }
    }
}
vector<string> wordBreak(string &s, vector<string> &dictionary)
{
    vector<string> ans;
    string ansString="";
    int n=s.length();
    solve(s,dictionary,ans,ansString,n,0);
    return ans;

}