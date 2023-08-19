#include <bits/stdc++.h> 
int findlargest(vector<int>& num,int index,int number)
{
    int larger=number;
    int indi=-1;
    for(int i=index;i<num.size();++i)
    {
        if(num[i]>=larger)
        {   larger=num[i];
            indi=i;
        }
    }
    if(larger==number)
    return -1;
    
    return indi;
}
void solve(vector<int>& num,int k,int index)
{
    if(k==0 || index==num.size())
    return;

    int largestIndex=findlargest(num,index+1,num[index]);
    if(largestIndex!=-1)
    {
        swap(num[index],num[largestIndex]);
        
        solve(num,k-1,index+1);
    }
    else{

    solve(num,k,index+1);
    }

}
vector<int> maxNumberKSwaps(vector<int> &num, int k){
    solve(num,k,0);
    return num;
}