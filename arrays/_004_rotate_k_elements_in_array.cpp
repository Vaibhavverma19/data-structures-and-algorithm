vector<int> rotateArray(vector<int>arr, int k) {
    k=k%arr.size();
    vector<int> temp(k,-1);
    for(int i=0;i<k;++i)
    {
        temp[i]=arr[i];
    }
    for(int i=k;i<arr.size();++i)
    {   
        arr[i-k]=arr[i];
    }
    int j=0;
    for(int i=arr.size()-k;i<arr.size();++i)
    {
        arr[i]=temp[i-(arr.size()-k)];
        j++;
        
    }

    return arr;
}

//approach 2:- tc-o(n) sc-o(1)  
// reverse from 0 to k-1   3,2,1,4,5
// reverse k to n-1        3,2,1,5,4
// reverse whole array      4,5,1,2,3.


