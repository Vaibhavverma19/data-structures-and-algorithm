#include <bits/stdc++.h> 
int prec(char ch)
{
    if (ch=='^') return 3;
    else if (ch=='/' || ch=='*') return 2;
    else if (ch=='+' || ch=='-') return 1;
    return -1;
}
int evaluatePostfix(string & str)
{
    stack<int>st;
    for (int i=0;i<str.size();i++)
    {
        if (isdigit(str[i]))
        {
            int temp=0;
            while(str[i]!='#')
            {
             temp*=10;
             temp+=(str[i]-'0');
             i++;
            }
            st.push(temp);
        }
        else{
            int op1=st.top();
            st.pop();

            int op2=st.top();
            st.pop();

            switch (str[i])
            {
                case '+':
                st.push(op1+op2);
                break;

                case '-':
                st.push(op2-op1);
                break;

                case '*':
                st.push(op2*op1);
                break;

                case '/':
                st.push(op2/op1);
                break;
            }

        }
    }
     return st.top();
}
string infixToPostfix(string &str)
{
    string ans="";
    stack<char>st;
    for (int i=0;i<str.size();i++)
    {
        if(str[i]>='0' && str[i]<='9')
        {
            string temp="";
            while(i<str.size() && isdigit(str[i]))
            {
                ans+=str[i];
                i++;
            }
            i--;
            ans+='#';
        }

        else if (str[i]=='(') st.push(str[i]);

        else if (str[i]==')')
        {
            while(st.top()!='(')
            {
                ans+=st.top();
                st.pop();
            }
            st.pop();
        }

        else{
            while(!st.empty() && prec(st.top())>=prec(str[i]))
            {
                ans+=st.top();
                st.pop();
            }
            st.push(str[i]);
        }
    }	
    while(!st.empty())
    {
        ans+=st.top();
        st.pop();
    }
    return ans;
}
int evaluateArithmeticExpression(string &expression) 
{
	string postfix=infixToPostfix(expression);
    return evaluatePostfix(postfix);
}