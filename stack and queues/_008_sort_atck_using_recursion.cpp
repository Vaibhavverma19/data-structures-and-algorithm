#include <bits/stdc++.h> 
void placeperfect(stack<int>& stack,int num)
{
	if(stack.empty() || num>stack.top())
	{
       stack.push(num);
	   return;
	}

	if(num<=stack.top())
	{
		int temp=stack.top();
		stack.pop();
		placeperfect(stack,num);
		stack.push(temp);
	}
}
void sortStack(stack<int> &stack)
{   if(stack.empty())
     return;

	int temp=stack.top();
	stack.pop();
	sortStack(stack);

	placeperfect(stack,temp);


}