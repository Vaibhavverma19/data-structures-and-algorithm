#include <bits/stdc++.h> 
/***************************************
 
    Following is the Node class already written.

    class Node 
    {
    public:
        int data;
        Node* next;
        Node* prev;

        Node(int data) 
        {
            next = NULL; prev=NULL;
            this->data = data;
        }

        ~Node() 
        {
            if (next != NULL)
            {
                delete next;
            }
        }
    };
 
***************************************/
void solve(Node* left,Node* right,int key,int& ans)
{
    if(left==NULL)
    return;

    

    while(left!=right)
    {
        if(left->data+right->data==key)
        {
           ans+=1;
           left=left->next;
        }else{
            if(left->data+right->data<key)
            {
                left=left->next;
            }else{
                right=right->prev;
            }
        }
    }
}
int countAllTripletSum(Node *head, int x)
{
    if(head==NULL)
    return 0;
    Node* tail=head;
    while(tail->next)
    {
        tail=tail->next;
    }
    int ans=0;
    for(Node* num1=head;num1;num1=num1->next)
    {
       solve(num1->next,tail,x-num1->data,ans);
    }

    return ans;
}