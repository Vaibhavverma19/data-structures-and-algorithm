#include <bits/stdc++.h> 
/****************************************************************

Following is the class structure of the Node class:

    class Node
    {
    public:
        int data;
        Node *next;
        Node(int data)
        {
	        this->data = data;
	        this->next = NULL;
        }
    };

*****************************************************************/

Node *delAddLastNode(Node *head){
	if(head==NULL)
    return NULL;
    if(head->next==NULL)
    return head;
    Node* curr=head;
    Node* prev;
    while(curr->next!=NULL)
    {
        prev=curr;
        curr=curr->next;
    }
    if(prev)
    {
        prev->next=NULL;
    }
    curr->next=head;
    head=curr;
    return head;

}