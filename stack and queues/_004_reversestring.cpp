#include <bits/stdc++.h> 
string kevinStackProblem(string &s)
{   string answer="";
	stack<char> st;
	 int i=0;
	while(i<s.length())
	{
		char ch=s[i++];
        st.push(ch);
	}
    while(!st.empty())
	{
		char ch=st.top();
		st.pop();
		answer=answer+ch;
	}
	return answer;
}
