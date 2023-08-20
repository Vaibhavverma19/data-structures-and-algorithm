/********************************************************

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

********************************************************/

Node *reverseLL(Node *head, int low, int high) {
	if(head==NULL)
	{
		return head;
	}
	Node* curr=head;
	Node* prev1=NULL;
	int k=high-low+1;
	while(--low && curr->data!=-1)
	{  prev1=curr;
		curr=curr->next;
	}
	//cout<<curr->data<<"..."<<endl;
	if(curr->data==-1)
	{
		return head;
	}
    Node* temp=curr;
	Node* frwrd;
	Node* prev=NULL;

	while(k && curr->data!=-1)
	{
		frwrd=curr->next;
		curr->next=prev;
		prev=curr;
		curr=frwrd;
		k--;

	}
	// cout<<"frwrd "<<frwrd->data<<endl;
	// cout<<"prev "<<prev->data<<endl;
	// cout<<"prev1 "<<prev1->data;
	temp->next=frwrd;
	if(prev1)
	{
	prev1->next=prev;
	return head;

	}
	return prev;



}