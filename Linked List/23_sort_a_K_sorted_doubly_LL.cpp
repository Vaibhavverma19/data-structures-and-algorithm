#include <bits/stdc++.h> 
/****************************************************************

    Following is the class structure of the Node class:

        class Node
        {
        public:
            int data;
            Node *next;
            Node *prev;
            Node(int data)
            {
                this->data = data;
                this->next = NULL;
                this->prev = NULL;
            }
        };

*****************************************************************/

Node *sortedDll(Node *head, int k)
{  if(!head)
   return head;

   priority_queue<int,vector<int>,greater<int> > minheap;

   Node* curr=head;
   int cnt=0;
   //enter first k values in pq so nlogk not nlogn 
   while(curr && cnt<=k )
   {
       minheap.push(curr->data);
       curr=curr->next;
       cnt++;
   }

   //now we have first position's value at the top of minheap.
   Node* temp=head;
   while(curr)
   {
       temp->data=minheap.top();
       minheap.pop();
       temp=temp->next;
       minheap.push(curr->data);
       curr=curr->next;
   }

   while(!minheap.empty())
   {
       temp->data=minheap.top();
       minheap.pop();
       temp=temp->next;
   }
  return head;
}