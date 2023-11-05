#include <bits/stdc++.h> 
void sort0and1(int n, vector<int> &a){
    int i=0;
    int j=a.size()-1;
    while(i<j)
    {
        //0,0
        if(a[i]==0 && a[j]==0)
        {
            i++;
            continue;
        }
        //0,1
         if(a[i]==0 && a[j]==1)
        {
            i++;
            j--;
            continue;
        }

        //1,0
         if(a[i]==1 && a[j]==0)
        {
            swap(a[i],a[j]);
            i++;
            j--;
            continue;
        }
        //1,1
         if(a[i]==1 && a[j]==1)
        {
            j--;
            continue;
        }
    }
}