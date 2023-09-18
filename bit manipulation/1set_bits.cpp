#include <bits/stdc++.h> 
#include <iostream>

using namespace std;

int countBits(int n)
{
    int cnt=0;
    while(n!=0)
    {
        if(n&1)
        {
            cnt++;  // 1&1 =1 otherwise 0.
        }
        
        n=n>>1;  //left shift by 1
        
    }
    return cnt;
}

int main() {
    int n;
    cin >> n;
    cout<<countBits(n);
    return 0;
}