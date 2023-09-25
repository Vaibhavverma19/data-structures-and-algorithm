#include <bits/stdc++.h> 

vector<int> maxOfSubarray(vector<int> arr, int n, int k) 

{

    // Write your code here

    vector<int> ans;

    multiset<int, greater<int> > pq;

 

    for(int i=0;i<n;i++)

    {

        if(pq.size()<k)

          pq.insert(arr[i]);

        else

        {

            ans.push_back(*pq.begin());

            pq.erase(pq.find(arr[i-k]));

            pq.insert(arr[i]);  

        }   

    }

    ans.push_back(*pq.begin());

    return ans;

}