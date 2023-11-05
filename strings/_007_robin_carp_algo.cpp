#include<bits/stdc++.h>
vector<int> stringMatch(string text, string pattern) {
	unordered_map<char,int> map;
	char c='a'; int i=1;
	while(c>='a' && c<='z')
	{
		map[c++]=i++;
	}
    int reqVal=0; int val=0;
	for(int i=0;i<pattern.length();++i)
	{
       reqVal+=map[pattern[i]];
	   val+=map[text[i]];
	}
    vector<int> ans;
	if(reqVal==val)
	{
		 if(text.substr(0,pattern.length())==pattern)
		 ans.push_back(1);
	}
    
	for(int i=pattern.length();i<text.length();++i)
	{  	val-=map[text[i-pattern.length()]];
		val+=map[text[i]];
        if(reqVal==val)
		{
		 if(text.substr(i-pattern.length()+1,pattern.length())==pattern)
		 ans.push_back(i-pattern.length()+2);
		}

	}

	return ans;
}
