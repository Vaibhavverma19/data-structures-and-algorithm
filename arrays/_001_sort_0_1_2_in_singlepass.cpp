#include <bits/stdc++.h> 
void sort012(int *arr, int n)
{
   int low=0; // to put all the zeros at the lower positions
   int mid=0; //to traverse the array 
   int high=n-1; // to put all the 2s at the higher positions
   while(mid<=high)
   {
      if(arr[mid]==0)
      {
         //put it at the current lowest pos available.
         swap(arr[low],arr[mid]);
         //since this pos is now filled therefor
         low++;
         mid++; // new arr[mid] cannot be 2 since its coming from back and if it were 2 it would have been processed.
         //thats why we are updating it.
      }else{
         if(arr[mid]==2)
         {
            swap(arr[mid],arr[high]);
            high--;
         }
         else{
            mid++;
         }
      }
   }
}