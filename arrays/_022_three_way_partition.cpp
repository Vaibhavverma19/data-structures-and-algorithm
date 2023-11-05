#include <bits/stdc++.h> 
vector<int> threeWayPartition(vector<int> &arr, int n, int a, int b)
{
   int la=0;
   int gb=0;
   for(auto x:arr)
   {
       if(x<a) la++;
       if(x>b) gb++;
   }

   int i=0,j=la,k=n-gb;
   while( i<la || j<n-gb || k<n )
   {
       if(arr[i]<a) i++;
       else{
           if(  arr[i]<=b)
           {
               swap(arr[i],arr[j++]);
           }else{
               swap(arr[i],arr[k++]);
           }
       }
   }
   return arr;
}