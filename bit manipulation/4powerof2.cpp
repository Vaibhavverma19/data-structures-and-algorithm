bool isPowerOfTwo(int n)
{	
    // int x=0;
    // while((1<<x)<n)
    // {
    //     x++;
    // }
    // if((1<<x)==n)
    // {
    //     return true;
    // }
    // else{
    //     return false;
    // }


    if(n & (n-1)){
        return false;
    }else{
        return true;
    }
}