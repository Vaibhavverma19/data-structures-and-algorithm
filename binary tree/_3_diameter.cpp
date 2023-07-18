class Solution {
  public:
    // Function to return the diameter of a Binary Tree.
    pair<int,int> solve(Node* root)
    {
        if(root==NULL)
        {
            return make_pair(0,0);
        }
        
        pair<int,int> op1=solve(root->left);
        pair<int,int> op2=solve(root->right);
        
        int op3=1+op1.first+op2.first;
        
        int height=max(op1.first,op2.first)+1;
        int dia=max(op1.second,max(op2.second,op3));
        
        return make_pair(height,dia);
    }
    int diameter(Node* root) {
     pair<int,int> ans;
     ans=solve(root);
     return ans.second;
    }
};