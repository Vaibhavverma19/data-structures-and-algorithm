void addatlast(stack<int>& stack,int num)
{
    if(stack.empty())
    {
        stack.push(num);
        return;
    }

    int temp=stack.top();
    stack.pop();

    addatlast(stack,num);

    stack.push(temp);
}
void reverseStack(stack<int> &stack) {
    //visit each element and place it at the last of the stack assume that we are placing each element at the 
    //last of already reversed stack having elements other than current element.

    if(stack.empty())
    return;

    int temp=stack.top();

    stack.pop();
    reverseStack(stack);

    addatlast(stack,temp);
}