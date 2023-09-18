// Stack class.
class Stack {
    int *arr;
    int index=-1;
    int size=0;
public:
    
    Stack(int capacity) {
        arr=new int[capacity];
        index=-1;
        size=capacity;
    }

    void push(int num) {
        if(index!=size-1)
        {
          index++;
          arr[index]=num;
        }
    }

    int pop() {
        if(index==-1)
        {
            return -1;
        }
        return arr[index--];
    }
    
    int top() {
         if(index==-1)
        {
            return -1;
        }

        return arr[index];
    }
    
    int isEmpty() {
        if(index==-1)
        {
            return 1;
        }else{
            return 0;
        }
    }
    
    int isFull() {
        if(index==size-1){
            return 1;
        }else{
           return 0;
        }
    }
    
};
