#include <bits/stdc++.h> 
int numberOfFlips(int a, int b)
{    
    int n=0;
    n=(a ^ b);
    int cnt=0;
    while(n!=0)
    {
        if(n & 1)
        {
           cnt++;
        }
            n = n>>1;
        
    }

    return cnt;
}