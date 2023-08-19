#include <bits/stdc++.h> 
void solve(vector<int>& arr,int& n,int& teamA,int& teamB,int n1,int n2,int player,int& mini)
{
    if(player==n)
    {
       mini=min(mini,abs(teamA-teamB));
       return;
    }

    //team A.
    if(n1)
    {
        
        teamA+=arr[player];
        solve(arr,n,teamA,teamB,n1-1,n2,player+1,mini);
        teamA-=arr[player];
    }
    

    //team b
    if(n2)
    {
        teamB+=arr[player];
        solve(arr,n,teamA,teamB,n1,n2-1,player+1,mini);
        teamB-=arr[player];
    }
        

}
int tugOfWar(vector<int> &arr, int n)
{  int n1,n2;
   if(n&1)
   {
       n1=(n-1)/2;
       n2=(n+1)/2;

   }
   else{
       n1=n/2;
       n2=n/2;
   }
   int mini=INT_MAX;
   int teamA=0;
   int teamB=0;
   solve(arr,n,teamA,teamB,n1,n2,0,mini);
   return mini;


}