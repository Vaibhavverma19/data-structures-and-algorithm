/****************************************************************

    Following is the class structure of the Node class:

        class Node
        {
        public:
            int data;
            Node *next;
            Node()
            {
                this->data = 0;
                next = NULL;
            }
            Node(int data)
            {
                this->data = data;
                this->next = NULL;
            }
            Node(int data, Node* next)
            {
                this->data = data;
                this->next = next;
            }
        };

*****************************************************************/
#include<bits/stdc++.h>

Node* findIntersection(Node *firstHead, Node *secondHead)
{  Node* temp1=firstHead;
  Node* temp2=secondHead;
   unordered_map<Node*,bool> map;
    while(temp1)
    {   //cout<<temp1->data<<" marked true "<<endl;
        map[temp1]=true;
        temp1=temp1->next;
    }
    while(temp2)
    {
        if(map[temp2]==true)
        {  //cout<<temp2->data<<"......"<<endl;
            return temp2;
            
        }
        else{
            map[temp2]=true;
            temp2=temp2->next;
        }
    }
    return NULL;
}
