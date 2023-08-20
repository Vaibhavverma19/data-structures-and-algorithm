/**
 * Definition of doubly linked list:
 * class Node {
 * public:
 *      int data;
 *      Node *prev;
 *      Node *next;
 *      Node() {
 *          this->data = 0;
 *          this->prev = NULL;
 *          this->next = NULL;
 *      }
 *      Node(int data) {
 *          this->data = data;
 *          this->prev = NULL;
 *          this->next = NULL;
 *      }
 *      Node (int data, Node *next, Node *prev) {
 *          this->data = data;
 *          this->prev = prev;
 *          this->next = next;
 *      }
 * };
 *
 *************************************************************************/

Node * removeDuplicates(Node *head)
{
    if(head==NULL || head->next==NULL)
    {
        return head;
    }

    Node* temp=head;
    while(temp!=NULL)
    {   
        Node* extra=temp->next;
        while(extra!=NULL && extra->data==temp->data )
        {
            extra=extra->next;
        }
       
        temp->next=extra;
            
        
        temp=temp->next;
    }

    return head;
}
