#include <bits/stdc++.h> 
int calculateSquare(int num)
{
   int temp=abs(num);
   int n=abs(num);
   int val=0;
   int pos=0;
   while(temp!=0)
   {
      if(temp&1)
      {
          val+=n<<pos;
      }
      pos++;
      temp=temp>>1;
   }

  
   return val;
}