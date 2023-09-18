int hp2(int n)
{
    int x=0;
    while((1<<x)<=n)
    {
        x++;
    }
    
    return x-1;
}
int countSetBits(int n) {
    if(n==0)
    return 0;
    int x=hp2(n);
    int rest=n-(1<<x);
    int ans=x*(1<<(x-1))%100000007 + (n-(1<<x) +1)%100000007 +countSetBits(rest)%100000007;
    return ans%100000007; 
}