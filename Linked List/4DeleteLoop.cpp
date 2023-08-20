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

bool detectAndRemoveCycle(Node* head)
{
 	if(head==NULL || head->next==NULL)
	return false;

    bool ans=false;
	Node* slow=head;
	Node* fast=head;
	
	while(  fast &&  fast->next)
	{
		slow=slow->next;
	    fast=fast->next->next;
	if(slow==fast)
	{  	slow=head;
	    if(slow==fast)
		{
			while(fast->next!=slow)
			{
				fast=fast->next;

			}
			fast->next=NULL;
			return true;
		}
		else{
			while(slow->next!=fast->next)
			{
				slow=slow->next;
				fast=fast->next;
			}
			fast->next=NULL;
			return true;

		}
	}
	}


	return ans;
}
