#include <bits/stdc++.h> 
class Queue{
    // Stacks to be used in the operations.
    stack<int> stk1, stk2;
    
    public:
    void putinlast(stack<int>& stk1,int X)
    {
        if(stk1.empty())
        {
            stk1.push(X);
            return;
        }

        int temp=stk1.top();
        stk1.pop();
        putinlast(stk1,X);
        stk1.push(temp);
    }
    // Enqueues 'X' into the queue. Returns true after enqueuing.
    bool enqueue(int X){
        
        putinlast(stk1,X);
        return true;
    }

    /*
      Dequeues top element from queue. Returns -1 if the queue is empty, 
      otherwise returns the popped element.
    */
    int dequeue(){
        if(stk1.empty())
        {
           return -1;
        }

        int ans= stk1.top();
        stk1.pop();
        return ans;
    }
};