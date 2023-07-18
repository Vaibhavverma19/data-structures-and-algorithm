/*************************************************************
    Following is the Binary Serach Tree node structure

    template <typename T>
    class TreeNode
    {
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
            if (left)
                delete left;
            if (right)
                delete right;
        }
    };

*************************************************************/
 void findInorderOfBT(TreeNode<int>* root,vector<int>& inorder)
    {
        if(root==NULL)
        {
            return;
        }
        
        //L
        findInorderOfBT(root->left,inorder);
        
        //N
        inorder.push_back(root->data);
        
        //R
        findInorderOfBT(root->right,inorder);
    }
TreeNode<int>* solve(vector<int>& inorder,int start,int end)
{
    if(start>end)
    return NULL;

    int mid=start+(end-start)/2;

    TreeNode<int>* root=new TreeNode<int>(inorder[mid]);

    root->left=solve(inorder,start,mid-1);
    root->right=solve(inorder,mid+1,end);

    return root;
}
TreeNode<int>* balancedBst(TreeNode<int>* root) {
    vector<int> inorder;
    findInorderOfBT(root,inorder);
    TreeNode<int>* temp=solve(inorder,0,inorder.size()-1);
    return temp;
}
