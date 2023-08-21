#include <bits/stdc++.h> 
/*****************************************************************
Following is the Linked list node structure already written

template <typename T>
class LinkedListNode
{
public:
    T data;
    LinkedListNode<T>* next;
    LinkedListNode(T data)
    { 
        this->data = data;
        next = NULL;
    }
};
*****************************************************************/
int solve(LinkedListNode<int>* head)
{
    if(head->data==-1)
    {
        return 1;
    }

    int carry=solve(head->next);
    head->data+=carry;
    carry=head->data/10;
    head->data%=10;
    return carry;
}
LinkedListNode<int>* addOneToList(LinkedListNode<int> *head)
{
    if(!head)
    {
        return head;
    }
    int carry=solve(head);
    if(carry>0)
    {
        LinkedListNode<int>* temp=new LinkedListNode<int> (carry);
        temp->next=head;
        head=temp;
    }

    return head;
}
