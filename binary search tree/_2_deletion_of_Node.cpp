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
    TreeNode* findpred(TreeNode* root)
    {
        if(root==NULL)
        return NULL;
        TreeNode* temp=root->left;
        while(temp->right!=NULL)
        {
            temp=temp->right;
        }

        return temp;
    }
    TreeNode* deleteNode(TreeNode* root, int key) {
        //pehle dekho ki root hai bhi ki nahi?
        if(root==NULL)
        return NULL;

        //jis node ko del karna hai agr vo mil gayi.
        if(root->val==key)
        {
            //0 child vala hai?
            if(root->left==NULL && root->right==NULL)
            { delete(root);
                return NULL;
            }
            
            //1 child vala hai?
            if(root->left==NULL && root->right!=NULL)
            {
                TreeNode* temp=root->right;
                delete(root);
                return temp;
            }
            if(root->left!=NULL && root->right==NULL)
            {
                TreeNode* temp=root->left;
                delete(root);
                return temp;
            }

            //2 child vala hai?
            if(root->left!=NULL && root->right!=NULL)
            {
                TreeNode* pred=findpred(root);
                root->val=pred->val;
                root->left=deleteNode(root->left,pred->val);
                return root;
            }


        }

        //agar nahi mila to kaha dhundhe?
        if(root->val>key)
        {
            root->left=deleteNode(root->left,key);
        }else{
            root->right=deleteNode(root->right,key);
        }

        return root;
    }
};