#include <bits/stdc++.h> 
/*

Following is the Node Structure written below
 
class node
{
	public:
	int data;
    node * next;
	node(int x)
	{
		data=x;
		next=NULL;
	}
};
*/

node *findKthFromLast(node *head, int k)
{
	node* slow=head;
	node* kNext=head;
	int cnt=k;
    while(kNext && cnt--)
	{
		kNext=kNext->next;
	}
	

	while(kNext)
	{
		kNext=kNext->next;
		slow=slow->next;
	}

	return slow;
}
