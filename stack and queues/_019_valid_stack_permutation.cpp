bool validStackPermutation(vector<int> &first, vector<int> &other){
	stack<int> st;
    int j=0;
	for(int i=0;i<first.size();++i)
	{
		st.push(first[i]);
        while(!st.empty() and st.top()==other[j])
		{
			st.pop();
			j++;
		}
	}
	if(j==other.size())
	{
		return true;
	}
}