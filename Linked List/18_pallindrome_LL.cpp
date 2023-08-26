#include <bits/stdc++.h> 
/****************************************************************

    Following is the class structure of the LinkedListNodeNode class:

    template <typename T>
    class LinkedListNodeNode
    {
    public:
        T data;
        LinkedListNodeNode<T> *next;
        LinkedListNodeNode(T data)
        {
            this->data = data;
            this->next = NULL;
        }
    };

*****************************************************************/

LinkedListNode<int> *reverse(LinkedListNode<int> *head) 
{ 
    LinkedListNode<int>* curr=head;
    LinkedListNode<int>* prev=NULL;
    LinkedListNode<int>* forwrd;
    while(curr)
    {
        forwrd=curr->next;
        curr->next=prev;
        prev=curr;
        curr=forwrd;
    }

    return prev;
}
bool isPalindrome(LinkedListNode<int> *head) {
   if(head==NULL)
   {
       return true;
   }
   LinkedListNode<int>* fast=head;
   LinkedListNode<int>* slow=head;
   while(fast->next && fast->next->next)
   {
       fast=fast->next->next;
       slow=slow->next;
   }

   LinkedListNode<int>* secondhalf=reverse(slow->next);

   LinkedListNode<int>* temp=head;
   while(secondhalf)
   {
       if(secondhalf->data!=temp->data)
       {
           return false;
       }

       secondhalf=secondhalf->next;
       temp=temp->next;
   }

   return true;

}