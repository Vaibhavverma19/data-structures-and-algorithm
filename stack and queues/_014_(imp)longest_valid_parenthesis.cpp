#include<bits/stdc++.h>
int longestValidParentheses(string s)
{
    stack<int> st;
    st.push(-1);
    int n=s.size();
    int ans=0;
    for(int i=0;i<n;i++)
    {
        if(s[i]=='(')
            st.push(i);
        else
        {
            st.pop();
            if(st.empty())
                st.push(i);
            else
                ans=max(ans,i-st.top());
        }
    }
    return ans;
}


//............................................

#include<stack>
#include<climits>
int findValidLength(int index,string& str){
    stack<char> st;
    int cnt=0;
    int tempans=0;
    while(index<str.length())
    {
        if(str[index]=='(')
        {
            st.push(str[index]);
        }else{
            if(str[index]==')')
            {  if(!st.empty())
                {

                    st.pop();
                    cnt+=2;
                    if(st.empty())
                    {
                    tempans+=cnt;
                    cnt=0;
                    }
                }else{
                    return tempans;
                }
                
            }
        }
        index++;
    }
    
    return tempans;
}
int longestValidParentheses(string str)
{
    int maxi=INT_MIN;
    for(int i=0;i<str.length();++i)
    {  char ch=str[i];
        if(ch=='(')
        {
            maxi=max(maxi,findValidLength(i,str));
        }
    }

    return maxi;
}