#include<bits/stdc++.h>
using namespace std;
int solve(int n)
{
    if(n==0)
    {return 1;}
     long ans=0;
    for(int i=0;i<n;++i)
    {
       ans+=solve(i)*solve(n-i);
    }

    return ans%1000000007;
}
int main(){
    int T;
    cin>>T;
    vector<int> a;
   for(int i=0;i<T;++i)
   {int temp;
     cin>>temp;
     a.push_back(temp);
   }

   for(int i=0;i<T;++i)
   {
       cout<<solve(a[i])<<endl;
   }
    return 0;
}