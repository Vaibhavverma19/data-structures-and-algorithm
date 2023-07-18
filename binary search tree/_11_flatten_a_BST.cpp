#include <bits/stdc++.h> 
/************************************************************

    Following is the Binary Tree node structure
    
    template <typename T>
    class TreeNode {
        public :
        T data;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }

        ~TreeNode() {
            if(left)
                delete left;
            if(right)
                delete right;
        }
    };

************************************************************/
void solve(TreeNode<int>* root,TreeNode<int>*& prev,TreeNode<int>*& head)
{
    if(root==NULL)
    return;

    solve(root->left,prev,head);

    if(prev==NULL)
    {   head=root;
        prev=root;
    }else{
        prev->right=root;
        prev->left=NULL;
        prev=root;
        prev->left=NULL;
    }

    solve(root->right,prev,head);
}
TreeNode<int>* flatten(TreeNode<int>* root)
{   TreeNode<int>* prev=NULL;
    TreeNode<int>* head=NULL;
    solve(root,prev,head);
    return head;

}
