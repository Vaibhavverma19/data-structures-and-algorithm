/**
 * Definition of linked list:
 *
 * class Node {
 * public:
 *      int data;
 *      Node *next;
 *      Node() {
 *          this->data = 0;
 *          this->next = NULL;
 *      }
 *      Node(int data) {
 *          this->data = data;
 *          this->next = NULL;
 *      }
 *      Node (int data, Node *next) {
 *          this->data = data;
 *          this->next = next;
 *      }
 * };
 *
 *************************************************************************/

Node *addTwoNumbers(Node *head1, Node *head2)
{
    int carry=0;
   
    Node* ans=new Node(-2);
    Node* tempans=ans;
    while(head1 || head2 )
    {
       int newdata;
       if(head1 && head2 )
       {
        newdata=head1->data+head2->data+carry;
        head1=head1->next;
        head2=head2->next;
       }
       else{

       if(head1)
       {
           newdata=head1->data+carry;
           head1=head1->next;
       }
       if(head2)
       {
           newdata=head2->data+carry;
           head2=head2->next;
       }
       }

       carry=newdata/10;
       newdata%=10;
       Node* newnode=new Node(newdata);
       tempans->next=newnode;
       tempans=newnode;
      
       
    }



    if(carry>0)
    {
        Node* last=new Node(carry);
        tempans->next=last;
        tempans=last;
    }
    Node* temp=ans;
    ans=ans->next;
    delete(temp);
    return ans;
}
