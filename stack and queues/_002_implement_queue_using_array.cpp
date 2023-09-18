#include <bits/stdc++.h> 
class Queue {
    int *arr;
    int frnt=-1;
    int rear=-1;
public:
    Queue() {
        arr=new int[100000];
        frnt=0;
        rear=-1;
    }

    /*----------------- Public Functions of Queue -----------------*/

    bool isEmpty() {
        if( frnt>rear)
        {
            return true;
        }
        return false;
    }

    void enqueue(int data) {
        rear+=1;
        arr[rear]=data;
    }

    int dequeue() {
        if( frnt<=rear)
        {   
            int temp=arr[frnt];
            arr[frnt]=-1;
            frnt=frnt+1;
            if(frnt==rear+1)
            {
                frnt=0;
                rear=-1;
            }
            return temp;
        }

        return -1;
    }

    int front() {
        if(frnt==-1 || frnt>rear)
        {
            return -1;
        }

        return arr[frnt];
    }
};