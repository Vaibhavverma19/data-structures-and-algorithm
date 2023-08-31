//partially correct one/


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
void extract(Node* head,long long& num1,int& digit1)
{
	if(head->next==NULL)
	{
		digit1+=1;
		num1+=head->data;
		return;
	}

	extract(head->next,num1,digit1);

	num1=head->data*pow(10,digit1) + num1;
	digit1+=1;

	

}
Node *multiplyLL(Node *head1, Node *head2)
{   
    long long  num1=0;
	int digit1=0;
    extract(head1,num1,digit1);
    long long num2=0;
	int digit2=0;
    extract(head2,num2,digit2);

	long long ans=num1*num2;

	Node* answer=new Node(0);
    stack<int> st;
	while(ans>0)
	{
       st.push(ans%10);
	   ans=ans/10;
	}
	if(st.empty())
	{
       return answer;
	}
    Node* temp=answer;
	while(!st.empty())
	{
		Node* newnode=new Node(st.top());
		st.pop();
		temp->next=newnode;
		temp=temp->next;
		
	}

	return answer->next;
}
