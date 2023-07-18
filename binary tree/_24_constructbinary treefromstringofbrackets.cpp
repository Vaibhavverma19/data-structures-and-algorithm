//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

/* A binary tree node has data, pointer to left
child and a pointer to right child */
class Node
{
public:
    int data;
    Node *left, *right;
    Node(int data)
    {
        this->data = data;
        this->left = this->right = NULL;
    }
};

/* This function is to print the inorder of the tree  */
void inorder(Node *root)
{
    if (root == NULL)
        return;
    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}



// } Driver Code Ends
//User function Template for C++

/*
class Node
{
public:
    int data;
    Node *left, *right;
    Node(int data)
    {
        this->data = data;
        this->left = this->right = NULL;
    }
};
*/


class Solution{
public:
    // function to construct tree from string
    Node* solve(string& str,int& index)
    {   if(str[index]==')')
        {
            index++;
            return NULL;
        }
        
        int num=0;
        while(index<=str.length() && isdigit(str[index]))
        {
            num=num*10 + (str[index]-'0');
            index++;
        }
        
        Node* root=new Node(num);
        
        if(index<=str.length() && str[index]=='(')
        {
            root->left=solve(str,++index);
        }
        
        if(index<=str.length() && str[index]=='(')
        {
            root->right=solve(str,++index);
        }
        index++;
        return root;
    }
    Node *treeFromString(string str){
        Node* ans;
        int index=0;
        
        ans=solve(str,index);
        return ans;
    }
};

//{ Driver Code Starts.

// Driver Code
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string str;
        cin >> str;
        Solution obj;
        Node *root = obj.treeFromString(str);
        inorder(root);
        cout << "\n";
    }
    return 0;
}

// } Driver Code Ends