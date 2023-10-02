long long maxSubarraySum(vector<int> arr, int n)
{
    long long sum=0;
    long long ans=0;

    for(int i=0;i<n;++i)
    {
        //step1: lets assume ki ye element max subarray ka part hai
        sum+=arr[i];

        //step2: check kro ki ab tk max ans kya ban rha hai kuki ho skta hai bich me kuch elements negative aa gye ho

        ans=max(ans,sum);

        //step3: sum agar zero se kam ho gaya mtlb abhi tk ke elements ko lene ka koi mtlb ni
        if(sum<=0)
        sum=0;
    }

    return ans;
}