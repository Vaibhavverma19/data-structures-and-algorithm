#include <bits/stdc++.h> 
class CircularQueue{
    int front;
    int rear;
    int size;
    int *arr;
    public:
    // Initialize your data structure.
    CircularQueue(int n){
       arr=new int[n];
       front=-1;
       rear=-1;
       size=n;
    }

    // Enqueues 'X' into the queue. Returns true if it gets pushed into the stack, and false otherwise.
    bool enqueue(int value){
        if((front+size-1)%size==rear)
        {
            //means queue is full so backoff
            return false;
        }

        if(front==-1)
        {
            front=rear=0;
            arr[rear]=value;

        }else{
            rear=(rear+1)%size;
            arr[rear]=value;
        }

        return true;


    }

    // Dequeues top element from queue. Returns -1 if the stack is empty, otherwise returns the popped element.
    int dequeue(){
        if(front==-1)
        {
            return -1;
        }
        int ans;
        if(front==rear)
        {
          ans=arr[front];
          front=rear=-1;
         
        }else{
            ans=arr[front];
            front=(front+1)%size;
        }
         return ans;
    }
};