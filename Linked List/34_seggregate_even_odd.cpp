/*
 * Definition for linked list.
 * class Node {
 *  public:
 *		int data;
 *		Node *next;
 *		Node() : data(0), next(nullptr) {};
 *		Node(int x) : data(x), next(nullptr) {}
 *		Node(int x, Node *next) : data(x), next(next) {}
 * };
 */

Node* segregateEvenOdd(Node* head)
{
   Node* temp=head;
    Node* odd=NULL;
    Node* even=NULL;
    Node* currOdd=odd;
    Node* currEven=even;
   while(temp)
   {
       if(temp->data%2!=0)
       {
           if(odd==NULL)
           {
               odd=temp;
               currOdd=odd;
              
           }
           else{
            currOdd->next=temp;
            currOdd=currOdd->next;
           }

            temp=temp->next;
            currOdd->next=NULL;
           
       }else{
            if(even==NULL)
           {
               even=temp;
               currEven=even;
              
           }
           else{
            currEven->next=temp;
            currEven=currEven->next;
           }

            temp=temp->next;
            currEven->next=NULL;
       }
   }

   currEven->next=odd;
   return even;
}
