/*
Following is the class structure of the Node class:

class Node
{
public:
    int data;
    Node *next,*prev;
    Node()
    {
        this->data = 0;
        next = NULL;
        prev= NULL;
    }
    Node(int data)
    {
        this->data = data; 
        this->next = NULL;
        this->prev= NULL;
    }
    Node(int data, Node* next, Node *prev)
    {
        this->data = data;
        this->next = next;
        this->prev= prev;
    }
};

*/

Node* reverseDLL(Node* head)
{   
  Node* temp=head;
  Node* forward=temp->next;

  while(forward)
  {
      temp->next=temp->prev;
      temp->prev=forward;
      
      forward=forward->next;

      temp=temp->prev;
  } 
  temp->next=temp->prev;
  temp->prev=NULL;
  return temp;
}

