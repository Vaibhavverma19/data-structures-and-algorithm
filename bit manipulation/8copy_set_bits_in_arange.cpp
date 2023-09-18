#include <bits/stdc++.h> 
int copyBitsInRange(int a, int b, int x, int y)
{
   int mask=1;
   int cnt=0;
   int val=0;
   while(cnt<=31)
   {
       if(cnt<x-1)
       {
           //find current bit of b
           int temp=mask<<cnt;
           if(temp & b)
           {
               val+=pow(2,cnt);
           }
           cnt++;
       }else{
           if( cnt<y){
           int temp=mask<<cnt;
           //find cyrr bit of a co we are in the range
           if(temp & a || temp & b)
           {
              val+=pow(2,cnt);
           }
           cnt++;

           }else{
               int temp=mask<<cnt;
               //again find curr bit of b because wea re out of the range
               if(temp & b)
               {
                   val+=pow(2,cnt);
               }
               cnt++;
           }
       }
   }
   return val;
}