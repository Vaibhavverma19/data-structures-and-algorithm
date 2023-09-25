#include <bits/stdc++.h> 
bool checkStringExpression(string str) {
	stack<char> st;
	for(auto ch:str)
	{
		if(ch=='(')
		{
			st.push(ch);
		}
		if(ch=='+' || ch=='-' || ch=='*' || ch=='/')
		{   if(!st.empty())
			st.push(ch);
		}
		if(ch==')')
		{
			if(st.top()=='(')
			{
				return true;
			}else{
				while(st.top()!='(')
				{
					st.pop();
				}
				st.pop();
			}
		}
	}

	if(st.empty())
	return false;

	return true;
}