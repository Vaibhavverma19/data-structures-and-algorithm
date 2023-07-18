class Solution{
    public:
    //Function to check whether a binary tree is balanced or not.
    pair<int,bool> solve(Node* root)
    {
        if (root==NULL)
        return make_pair(0,true);
        
        pair<int,bool> left=solve(root->left);
        
        pair<int,bool> right=solve(root->right);
        
        if(abs(left.first-right.first)>1)
        {
        
           return make_pair(1+max(left.first,right.first),false);
        }
        
        bool temp=left.second && right.second;
        return make_pair(1+max(left.first,right.first),temp);
        
    }
    bool isBalanced(Node *root)
    {
       
        pair<int,bool> ans=solve(root);
        return ans.second;
    }
};