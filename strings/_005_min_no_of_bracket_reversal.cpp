#include <bits/stdc++.h> 
int findMinimumCost(string str) {
  stack<char> st;
  int i=0;
  while(i<str.length())
  {
     if(str[i]=='{')
     {
       st.push('{');

     }else{
       if(!st.empty() && st.top()=='{')
       {
         st.pop();
       }else{
         st.push('}');
       }
     }

     i++;
  }
 if(st.empty()) return 0;
  if(st.size() & 1 )
  {
    return -1;
  }else{
   int ans=0;
    while(!st.empty())
    {
      char c1=st.top();
      st.pop();
      char c2=st.top();
      st.pop();
      if(c1==c2)
      {
        ans++;
      }else{
        ans+=2;
      }
    }
    return ans;
  }
}