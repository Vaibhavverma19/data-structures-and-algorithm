#include <bits/stdc++.h> 
class NQueue{
    int *arr;
    int *front;
    int *temp; // if arr[i] is empty then temp[i] will represent the next free spot
    // if its not empty then temp[i] will represent that if we remove this element(front element) then what will be our new front.
    int freespot=0;
public:
    // Initialize your data structure.
    NQueue(int n, int s){
       arr=new int[s];
       front=new int[n];
       temp=new int[s];

       for(int i=0;i<s;++i)
       {
           arr[i]=0;
           if(i+1<s)
           {
               temp[i]=i+1;
           }
       }
       temp[s-1]=-1;

       for(int i=0;i<n;++i)
       {
           front[i]=-1;
       }
    }

    // Enqueues 'X' into the Mth queue. Returns true if it gets pushed into the queue, and false otherwise.
    bool enqueue(int x, int m){
        if(freespot==-1)
        return false;
        //step:1 find the index at which we will insert in arr.
        int index=freespot;

        //step2: insert
        arr[index]=x;

        //step3: update freespot by next freespot.     
        freespot=temp[index];

        //step4: mark this element as the last element of the respected queue.
        temp[index]=-1;
        
        //step4:update the last element of queue
        //if its first element of queue then dont need to find and update last element.
        if(front[m-1]==-1)
        {
            front[m-1]=index;
            
            return true;

        }
     
       //find and updating the curr last position of queue with new last
        int i=front[m-1];
        while(temp[i]!=-1)
        {
            i=temp[i];
        }
        temp[i]=index;

        
        return true;
        
    }

    // Dequeues top element from Mth queue. Returns -1 if the queue is empty, otherwise returns the popped element.
    int dequeue(int m){
        //step1: find the index of element to be deleted.
        int index=front[m-1];

        //if index is -1 then return queue is empty
        if(index==-1)
        {
            return -1;
        }
        int element=arr[index];
        
        //step2: update front with new front.
        front[m-1]=temp[index];
        
        //step3: since now arr[index] is empty so temp[index] will represent the net free spot
        temp[index]=freespot;
        //now this index itself become the current free spot because we just deleted the element at this index.
        freespot=index;

        return element;


    }
};