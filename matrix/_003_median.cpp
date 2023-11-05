#include <bits/stdc++.h> 
int findMedian(vector<vector<int> > &arr, int n, int m){

    

    priority_queue<int> pq;

 

    for(int i=0; i<n; i++){

        for(int j=0; j<m; j++){

           pq.push(arr[i][j]);

        }

    }

 

   
        int t=pq.size()/2;
        while(t--)
        {
            pq.pop();
        }

        return pq.top();
    
 

   

}
