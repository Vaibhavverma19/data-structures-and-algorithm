/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* solve(TreeNode* root)
    {
        if(root==NULL || (root->left==NULL && root->right==NULL))
        {
            return root;
        }
        TreeNode* temp=NULL;
        

        temp=root->left;
        root->left=root->right;
        root->right=temp;
        
        root->left=solve(root->left);
        root->right=solve(root->right);

        return root;
    }
    TreeNode* invertTree(TreeNode* root) {
        if(root==NULL || (root->left==NULL && root->right==NULL))
        {
            return root;
        }

        TreeNode* ans=solve(root);
        return ans;
    }
};