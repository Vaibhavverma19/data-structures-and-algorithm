#include <bits/stdc++.h> 
vector<int> separateNegativeAndPositive(vector<int> &nums){
   int negative=0;
   int trv=0;
   while(trv<nums.size())
   {  //if num neg
       if(nums[trv]<0)
       {
           swap(nums[trv],nums[negative]);
           negative++;
           trv++;
       }else{
           trv++;
       }
   }
   return nums;
}