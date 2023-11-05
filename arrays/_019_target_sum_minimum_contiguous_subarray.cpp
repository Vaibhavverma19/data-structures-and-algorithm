#include <bits/stdc++.h> 
int minSubArrayLen(vector<int>& arr, int target, int n) {
    int curr=0;
    int ans=0;
    int window_size=INT_MAX;
    int sum=0;
    int head=0;

    while(curr<n)
    {
        sum+=arr[curr];
        if(sum>target)
        {
            window_size=curr-head+1;
            ans=window_size;
            window_size--;
            sum=0;
            head=curr-window_size+1;
            curr=head;
        }else{
            if(curr+1-head > window_size)
            {
               sum-=arr[head];
               head++;
            }

            curr++;
        }
    }
    
    return ans;
}
