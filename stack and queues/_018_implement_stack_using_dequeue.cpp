#include <bits/stdc++.h> 
class Stack
{ deque<int> de;
public:
    
    // Pushes 'X' into the stack. Returns true if it gets pushed into the stack, and false otherwise.
    bool push(int x)
    {
        de.push_back(x);
        return true;
    }

    // Pops top element from Stack. Returns -1 if the stack is empty, otherwise returns the popped element.
    int pop()
    {    
        if(de.empty())
        {
            return -1;
        }
        int ans=de.back();
        de.pop_back();

         return ans;
    }

    // Returns the topmost element of the stack. In case the stack is empty, it returns -1.
    int top()
    {
        if(de.empty())
        {
            return -1;
        }
        return de.back();
    }

    // Returns true if the stack is empty, otherwise false.
    bool isEmpty()
    {
        return de.empty();
    }

    // Returns the number of elements currently present in the stack.
    int size()
    {
        return de.size();
    }
};