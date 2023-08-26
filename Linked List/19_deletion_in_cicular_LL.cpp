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

Node* deleteNode(Node* head, int key) 
{
    if(head==NULL)
    return head;
    if(head->data==key && head->next==head)
    {     //cout<<"yes:";
      
           return NULL;
        
        
    }
    Node* curr=head->next;
    Node* prev=head;
    int temp=0;
    while(curr!=head->next || temp==0)
    {    temp=1;
            
            if(curr->data==key)
            {  if(curr==head)
               {
                       head=head->next;
               }
               prev->next=curr->next;
               curr->next=NULL;
               return head;
               
            }
            prev=curr;
            curr=curr->next;

            
    }

    return head;
}