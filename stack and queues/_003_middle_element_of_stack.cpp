#include <bits/stdc++.h> 
void solve(stack<int>&inputStack, int steps)
{
   if(steps==0)
   {
      inputStack.pop();
      return;
   }

   int temp=inputStack.top();
   inputStack.pop();
   solve(inputStack,steps-1);
   inputStack.push(temp);
}
void deleteMiddle(stack<int>&inputStack, int N){
	
   int steps=0;
   int mid=0;
   if((N+1)%2==0)
   {  //6 == 3 steps chahiye hai 4
      // 8==4 steps chahiye hai 5
     mid=(N+1)/2;
     steps=mid-1;
   }else{
      //5 == 2 , steps chahiye hai 3
      //7==3 steps chahiye 4.
      mid=(N+1)/2;
      steps=mid;
   }

   

  
   solve(inputStack,steps);
   
}