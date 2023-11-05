#include <bits/stdc++.h> 
void solve(string &str,vector<string>& ans,string& temp,int index,int n)
{
	if(index==n)
	{  if(temp.length())
		ans.push_back(temp);
		return;
	}

	//include
	temp.push_back(str[index]);
	solve(str,ans,temp,index+1,n);
	temp.pop_back();

	solve(str,ans,temp,index+1,n);
}
vector<string> subsequences(string str){
	
	string temp="";
	vector<string> ans;
	int n=str.length();
	solve(str,ans,temp,0,n);
	return ans;
	
}
