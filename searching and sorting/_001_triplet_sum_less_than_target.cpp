#include <bits/stdc++.h> 
int threeSumSmaller(int n, vector<int> arr, int target) {
    sort(arr.begin(),arr.end());
    int cnt=0;
    for(int i=0;i<n;++i)
    {
        

       int j=i+1;
       int k=n-1;
       while( j<k)
       {
           int sum=arr[i]+arr[j]+arr[k];
           if(sum<target)
           {  
              cnt+=k-j;
              j++;
           }
           else{
             k--;
           }
       }
        
    }
    return cnt;
}
