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
    TreeNode* solve(vector<int>& preorder,int start,int end)
    {   if(start>end)
        return NULL;
        if(start==end)
        {
            TreeNode* temp=new TreeNode(preorder[start]);
            return temp; 
        }

        TreeNode* temp=new TreeNode(preorder[start]);

        int i=start+1;
        while(i<=end && preorder[start]>preorder[i] )
        {
            i++;
        }
        i--;
        temp->left=solve(preorder,start+1,i);
        temp->right=solve(preorder,i+1,end);

        return temp;
    }
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        TreeNode* root;
        
        root=solve(preorder,0,preorder.size()-1);
        return root;
    }
};