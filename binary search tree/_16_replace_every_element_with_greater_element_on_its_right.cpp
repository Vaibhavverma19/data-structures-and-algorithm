#include <bits/stdc++.h> 
class Node{
    public:
    int data;
    Node* left;
    Node* right;
    
    Node(int val)
    {
        data=val;
        left=NULL;
        right=NULL;
    }

};
Node* insertinbst(Node* root,int val,int& succ)
{
    if(root==NULL)
    {
        Node* newnode=new Node(val);
        return newnode;
    }

    if(val>=root->data)
    {
        root->right=insertinbst(root->right,val,succ);
    }
    else{
        succ=root->data;
        root->left=insertinbst(root->left,val,succ);
    }
    return root;
}
vector<int> leastGreaterElement(vector<int> &arr) 
{
   int n=arr.size();
   Node* root=NULL;
   //traverse from right to left because if right elements are already in the tree then only we can use them as successor.
   for(int i=n-1;i>=0;--i)
   {
       int succ=-1;
       root=insertinbst(root,arr[i],succ);
       arr[i]=succ;
   }
   return arr;
}