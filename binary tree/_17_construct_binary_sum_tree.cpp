int solve(Node* root)
    {
        if(root==NULL)
        return 0;
        int temp=root->data;
        
        int left=solve(root->left);
        int right=solve(root->right);
        
        root->data=left+right;
        
        return temp+root->data;
    }
    void toSumTree(Node *node)
    {
        solve(node);
    }