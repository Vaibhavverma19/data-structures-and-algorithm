#include <bits/stdc++.h> 
/************************************************************

    Following is the linkedList class structure:

    class Node {
    public:
        int data;
        Node *next;

        Node(int val) {
            this->data = val;
            next = NULL;
        }
        ~Node() {
            if (next != NULL) {
                delete next;
            }
        }
};

************************************************************/
      
Node* intersect_ll(Node* L1, Node *L2){

    Node* ans=new Node(-1);
    Node* dummy=ans;
    Node* temp1=L1;
    Node* temp2=L2;

    while(temp1 && temp2)
    {
        if(temp1->data==temp2->data)
        {
            Node* newnode=new Node(temp1->data);
            dummy->next=newnode;
            dummy=newnode;
            temp1=temp1->next;
            temp2=temp2->next;
        }
        else{
            if(temp1->data<temp2->data)
            {
                temp1=temp1->next;
            }else{
                temp2=temp2->next;
            }
        }
    }

    ans=ans->next;
    return ans;
    
}