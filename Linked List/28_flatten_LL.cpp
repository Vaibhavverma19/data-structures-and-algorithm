/*
 * Definition for linked list.
 * class Node {
 *  public:
 *		int data;
 *		Node *next;
 * 		Node *child;
 *		Node() : data(0), next(nullptr), child(nullptr){};
 *		Node(int x) : data(x), next(nullptr), child(nullptr) {}
 *		Node(int x, Node *next, Node *child) : data(x), next(next), child(child) {}
 * };
 */
Node* merge(Node* head1,Node* head2)
{
	Node* tempans=new Node(-1);
	Node* temp=tempans;

	while(head1 && head2)
	{
		if(head1->data<=head2->data)
		{
			temp->child=head1;
			head1=head1->child;
			temp=temp->child;
		}else{
			temp->child=head2;
			head2=head2->child;
			temp=temp->child;
		}
	}
	while(head1)
	{
		temp->child=head1;
		head1=head1->child;
		temp=temp->child;
	}
	while(head2)
	{
		    temp->child=head2;
			head2=head2->child;
			temp=temp->child;
	}
	return tempans->child;
}
Node* flattenLinkedList(Node* head) 
{  if(head==NULL )
    return head;

	Node* temp=head->next;
	head->next=NULL;
	
	

	Node* head2=flattenLinkedList(temp);

	Node* ans=merge(head,head2);

	return ans;

}
