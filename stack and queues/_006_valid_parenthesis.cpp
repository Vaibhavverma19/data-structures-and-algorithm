bool check(char c1,char c2)
{
    if(c2=='}' && c1=='{')
    {
        return true;
    }
    if(c2==')' && c1=='(')
    {
        return true;
    }
    if(c2==']' && c1=='[')
    {
        return true;
    }

    return false;
}
bool isValidParenthesis(string s)
{  stack<char> st;
    for(auto ch:s)
    {
        if(ch=='{' || ch=='[' || ch=='(')
        {
          st.push(ch);
        }else{
            if(st.empty())
            {
                return false;
            }
            char temp=st.top();
            
            bool result=check(temp,ch);
            if(!result)
            {
                return false;
            }
            st.pop();
        }
    }

    if(st.empty())
    {
    return true;
    }
        
    else{
        return false;
    }
}