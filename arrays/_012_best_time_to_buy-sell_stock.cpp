#include <bits/stdc++.h> 
int maximumProfit(vector<int> &prices){
   int n=prices.size();
    int greatest=prices[n-1];
   int ans=0;
   for(int i=n-2;i>=0;--i)
   {
      ans=max(ans,greatest-prices[i]);
      greatest=max(greatest,prices[i]);
      
   }

   return ans;
}