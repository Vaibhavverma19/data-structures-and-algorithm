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
Node* partition(Node* head)
{
	Node* pivot=head;
	Node* left=new Node(-1);
	Node* right=new Node(-1);

    Node* leftTemp=left;
	Node* rightTemp=right;
	Node* curr=head->next;

	while(curr)
	{
		if(curr->data<=pivot->data)
		{
			leftTemp->next=curr;
			curr=curr->next;
			leftTemp=leftTemp->next;
			leftTemp->next=NULL;
		}else{
			rightTemp->next=curr;
			curr=curr->next;
			rightTemp=rightTemp->next;
			rightTemp->next=NULL;
		}

		
	}
   
	left=left->next;
	right=right->next;

	pivot->next=right;

	return left;


}
Node *quickSortLL(Node *head)
{
    if(head==NULL || head->next==NULL)
	{
		return head;
	}
	Node* temppivot=head;
	Node* leftsubLL=partition(head);
	Node* rightsubLL=temppivot->next;

	leftsubLL=quickSortLL(leftsubLL);

	rightsubLL=quickSortLL(rightsubLL);
    if(leftsubLL)
	{

    Node* temp=leftsubLL;
	while(temp->next)
	{
		temp=temp->next;
	}
	temp->next=temppivot;
	temppivot->next=rightsubLL;

	return leftsubLL;
	}else{
		temppivot->next=rightsubLL;
		return temppivot;
	}

}