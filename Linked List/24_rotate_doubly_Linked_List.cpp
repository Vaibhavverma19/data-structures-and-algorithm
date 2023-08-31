#include <bits/stdc++.h> 
/****************************************************

    Following is the class structure of the DLLNode class:

    class DLLNode {
    public:
	int data;
	Node *next;

	DLLNode(int data) {
		this->data = data;
		this->next = NULL;
		this->prev = NULL;
	}
}

*****************************************************/

DLLNode* rotateDLL(DLLNode* head, int k) 
{  if(head==NULL)
    return head;
   DLLNode* tail=head;
   while(tail->next!=NULL)
   {
	   tail=tail->next;
   }

   DLLNode* temp=head;

   while(k>0)
   {
	   temp->prev=tail;
	   tail->next=temp;
	   tail=temp;
	   temp=temp->next;
        temp->prev=NULL;
       tail->next=NULL;
       k-=1;
   }
      

   return temp;

}