/********************************************************************

    Following is the representation of the Singly Linked List Node:

    class node{
        public:
            int data;
            node * next;
            node(int data){
                this->data=data;
                this->next=NULL;
            }
    };
    
********************************************************************/
node* findmid(node* head)
{
    node* slow=head;
    node* fast=head;
    while(slow && fast->next && fast->next->next)
    {
        fast=fast->next->next;
        slow=slow->next;
    }

    return slow;
}
node* merge(node* left,node* right)
{   
    node* ans=new node(-1);
    node* dummy=ans;
    while(left && right)
    {
        if(left->data<=right->data)
        {
          ans->next=left;
          left=left->next;
          ans=ans->next;
          
        }
        else{

        if(left->data>right->data)
        {
          ans->next=right;
          right=right->next;
          ans=ans->next;
        }
        }
    }
    if(left)
    {
        ans->next=left;
    }
    if(right)
    {
        ans->next=right;
    }

    dummy=dummy->next;
    return dummy;
}
node* mergeSort(node *head) {
    if(head==NULL || head->next==NULL)
    return head;

    node* mid=findmid(head);

    node* left=head;
    node* right=mid->next;
    mid->next=NULL;

    //now the linked list is completely split into two parts.

    //apply merge sort now.
    left=mergeSort(left);
    right=mergeSort(right);

    //we got two sorted linked list now we just have to merge them.
    node* finallist=merge(left,right);

    return finallist;
}
