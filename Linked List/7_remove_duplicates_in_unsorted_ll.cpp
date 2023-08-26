#include <bits/stdc++.h> 
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

Node *removeDuplicates(Node *head)
{
   unordered_map<int,bool> map;
   Node* temp=head;
   Node* prev;
   while(temp)
   {
       if(map[temp->data]!=true)
       {
           map[temp->data]=true;
           prev=temp;
           temp=temp->next;
       }
       else{
           prev->next=temp->next;
           temp=prev->next;
       }
   }
   return head;
}