#include <bits/stdc++.h> 
vector<vector<string> > ans;
bool isPallindrome(string& s)
{
    for(int i=0,j=s.length()-1;i<j;++i,--j)
    {
        if(s[i]!=s[j])
        {
            return false;
        }
    }

    return true;
}
void solve(string& s,vector<string>& tempAns,int index)
{
    if(index==s.length())
    {
        ans.push_back(tempAns);
        return;
    }

   string word="";
   for(int i=index;i<s.length();++i)
   {
       word+=s[i];
       if(isPallindrome(word))
       {  tempAns.push_back(word);
           solve(s,tempAns,i+1);
           tempAns.pop_back();
       }
   }
}
vector<vector<string> > partition(string &S)
{   while(ans.size())
    {
        ans.pop_back();
    }
    vector<string> tempAns;
    solve(S,tempAns,0);
    return ans;

}