#include <bits/stdc++.h>

int lengthOfLongestConsecutiveSequence(vector<int> &arr, int n) {
    int ans=INT_MIN;
    unordered_set<int> set;
    for(int i=0;i<n;++i)
    {
        set.insert(arr[i]);
    }
    
    for(auto it: set)
    {
        if(set.find(it-1)==set.end())
        {
           int cnt=1;
           int x=it;
           while(set.find(x+1)!=set.end())
           {
               cnt++;
               x+=1;
           }
           ans=max(ans,cnt);
        }
    }

    return ans;
}