#include <bits/stdc++.h> 
vector<int> sortedMatrix(vector<vector<int>> &mat, int n) {
    priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int> >>> pq;
    for(int i=0;i<n;++i)
    {
        pq.push({mat[i][0],{i,0}});
    }
    vector<int> ans;
    while(!pq.empty())
    {   auto it=pq.top();
        int data=it.first;
        int x=it.second.first;
        int y=it.second.second;
        pq.pop();
        ans.push_back(data);
        if(y<n-1)
        { 
            pq.push({mat[x][y+1],{x,y+1}});
        }
        
    }
return ans;
}