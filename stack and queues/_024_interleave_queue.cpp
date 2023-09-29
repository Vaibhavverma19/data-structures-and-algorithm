#include <bits/stdc++.h> 
void interLeaveQueue(queue < int > & q) {
    queue<int>q1;
    int n=q.size();
    int k=n/2;
    while(k--)
    {
       q1.push(q.front());
       q.pop();
    }
    
    while(!q1.empty())
    {
        q.push(q1.front());
        q1.pop();
        q.push(q.front());
        q.pop();
    }
}