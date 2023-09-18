#include <bits/stdc++.h> 
class NStack
{  int *arr; //main array
   int *top;  // array to store top of each stack.
   int *next; // if arr[i] is empty then next[i] will denote the second top of a particular stack
   // if arr[i] is not empty then it will denote the next available space.
   int freespot=0;
   
public:
    // Initialize your data structure.
    NStack(int N, int S)
    {   int n=N;
        int s=S;
        arr=new int[s];

        top=new int[n];

        next=new int[s];

        for(int i=0;i<s;++i)
        {
            arr[i]=0;
            if(i<s-1)
            next[i]=i+1;
        }
        next[s-1]=-1;

        for(int i=0;i<n;++i)
        {
            top[i]=-1;
        }
    }

    // Pushes 'X' into the Mth stack. Returns true if it gets pushed into the stack, and false otherwise.
    bool push(int x, int m)
    {   if(freespot==-1)
         return false;
        int index=freespot;

        freespot=next[index];

        arr[index]=x;

        next[index]=top[m-1]; // it will trace the index of prev stored number in the stack for pop operation

        top[m-1]=index;
        
        return true;

    }

    // Pops top element from Mth Stack. Returns -1 if the stack is empty, otherwise returns the popped element.
    int pop(int m)
    {
        int index=top[m-1];
        if(index<0)
        return -1;

        top[m-1]=next[index];

        int x=arr[index];
        //arr[index]=-1;

        next[index]=freespot;

        freespot=index;
        return x;
    }
};