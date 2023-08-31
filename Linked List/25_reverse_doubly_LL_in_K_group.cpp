#include <bits/stdc++.h> 
/*********************************************************

    Following is the class structure of the Node class:

    class Node
	{
	public:
	    int data;
	    Node *next;
	    Node *prev;
	    Node(int data)
	    {
	        this->data = data;
	        this->next = NULL;
	        this->prev = NULL;
	    }
	};

************************************************************/

Node* reverseDLLInGroups(Node* head, int k)
{	
    if(head==NULL || head->next==NULL)
	{
		return head;
	}

	Node* back=NULL;
	Node* curr=head;
	Node* front=head->next;
    int cnt=k;
	while(curr  && cnt--)
	{
		curr->next=back;
		curr->prev=front;
		back=curr;
		curr=front;
		if(front!=NULL)
		front=front->next;
	}
    
	back->prev=NULL;
	
	head->next=reverseDLLInGroups(curr,k);
	if(head->next)
	{
		head->next->prev=head;
	}
    //cout<<"..."<<back->data<<endl;
	return back;
}


