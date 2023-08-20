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

bool detectCycle(Node *head){
	if(head==NULL || head->next==NULL)
	return false;

	Node* slow=head;
	Node* fast=head->next;
	// slow=slow->next;
	// fast=fast->next->next;
	while(  fast &&  fast->next)
	{
		slow=slow->next;
	    fast=fast->next->next;
	if(slow==fast)
	{
		return true;
	}
	}

	return false;
}
