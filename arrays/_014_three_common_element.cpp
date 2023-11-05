#include <bits/stdc++.h> 
vector<int> findCommonElements(vector<int> &a, vector<int> &b, vector<int> &c)
{   vector<int> ans;
    int i=0,j=0,k=0;
    while(i<a.size() && j<b.size()  && k<c.size())
    {
        if(a[i]==b[j] && b[j]==c[k])
        {  if(!ans.empty())
           {
               if(ans.back()!=a[i])
               {
                   ans.push_back(a[i]);
                  
               }
           }
           else{
               ans.push_back(a[i]);
           }

            i++;
            j++;
            k++;
        }
        else{
            int max=a[i]>b[j]?(a[i]>c[k]?a[i]:c[k]):(b[j]>c[k]?b[j]:c[k]);
            
            if(a[i]<max)
            {
                i++;
            }
            if(b[j]<max)
            j++;
            if(c[k]<max) k++;
        }
    }

    return ans;
}