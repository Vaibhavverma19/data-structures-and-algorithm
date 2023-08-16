#include <bits/stdc++.h> 
int findMinRemovals(string& str)
{
    stack<char> st;
    for(int i=0;i<str.length();++i)
    {
        char ch=str[i];
        if(ch=='(')
        {
            st.push(ch);
        }
        if(ch==')')
        {
          if(!st.empty() && st.top()=='(')
            {
                st.pop();
            }
            else{
                st.push(ch);
            }
        }
    }

    return st.size();
}
bool isvalid(string& str)
{
    stack<char> st;
    for(int i=0;i<str.length();++i)
    {
        char ch=str[i];
        if(ch=='(')
        {
            st.push(ch);
        }
        if(ch==')')
        {
            if(!st.empty() && st.top()=='(')
            {
                st.pop();
            }
            else{
                st.push(ch);
            }
        }
    }

    if(st.empty())
    {
        return true;
    }

    return false;
}
void solve(string& str,vector<string>& ans,int mini, unordered_map<string,bool>& track)
{    if(track[str]==true)
    {
        return;
    }
    track[str]=true;
    if(mini==0)
    {   if(isvalid(str))
        ans.push_back(str);
        return;
    }
    
    for(int i=0;i<str.length();++i)
    {    string temp=str;
        string leftSubstr=str.substr(0,i);
        string rightSubstr=str.substr(i+1);
        str=leftSubstr+rightSubstr;
        solve(str,ans,mini-1,track);
        str=temp;
    }


}
vector<string> minRemovaltoMakeStringValid(string &str)
{
   int mini=findMinRemovals(str);
   vector<string> ans;
   unordered_map<string,bool> track;
   solve(str,ans,mini,track);
   return ans;
}
#include <bits/stdc++.h> 
int findMinRemovals(string& str)
{
    stack<char> st;
    for(int i=0;i<str.length();++i)
    {
        char ch=str[i];
        if(ch=='(')
        {
            st.push(ch);
        }
        if(ch==')')
        {
          if(!st.empty() && st.top()=='(')
            {
                st.pop();
            }
            else{
                st.push(ch);
            }
        }
    }

    return st.size();
}
bool isvalid(string& str)
{
    stack<char> st;
    for(int i=0;i<str.length();++i)
    {
        char ch=str[i];
        if(ch=='(')
        {
            st.push(ch);
        }
        if(ch==')')
        {
            if(!st.empty() && st.top()=='(')
            {
                st.pop();
            }
            else{
                st.push(ch);
            }
        }
    }

    if(st.empty())
    {
        return true;
    }

    return false;
}
void solve(string& str,vector<string>& ans,int mini, unordered_map<string,bool>& track)
{    if(track[str]==true)
    {
        return;
    }
    track[str]=true;
    if(mini==0)
    {   if(isvalid(str))
        ans.push_back(str);
        return;
    }
    
    for(int i=0;i<str.length();++i)
    {    string temp=str;
        string leftSubstr=str.substr(0,i);
        string rightSubstr=str.substr(i+1);
        str=leftSubstr+rightSubstr;
        solve(str,ans,mini-1,track);
        str=temp;
    }


}
vector<string> minRemovaltoMakeStringValid(string &str)
{
   int mini=findMinRemovals(str);
   vector<string> ans;
   unordered_map<string,bool> track;
   solve(str,ans,mini,track);
   return ans;
}
