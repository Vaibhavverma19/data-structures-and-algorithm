#include <bits/stdc++.h> 
int findSetBit(int N) {   
    int cnt=1;
    bool flag=false;
    int tempans;
    while(N!=0){
    if(N & 1)
    {
       if(flag==false)
       {
           flag=true;
           tempans=cnt;
       }
       else{
           
           return -1;
       }
    }else{
        cnt+=1;
    }
        N=N>>1;
    }
    if(flag)
    return tempans;
   
    return -1;
  
}

