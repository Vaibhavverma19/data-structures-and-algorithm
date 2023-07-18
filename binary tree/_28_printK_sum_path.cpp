#include <bits/stdc++.h> 
/************************************************************

    Following is the TreeNode class structure

    template <typename T>
    class TreeNode {
       public:
        T data;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T data) {
            this->data = data;
            left = NULL;
            right = NULL;
        }
    };

************************************************************/
void solve(TreeNode<int>* root,int k,int& ans)
{   
    if(root==NULL)
    {
        return;
    }
    if(k-root->data==0)
    ans++;

    solve(root->left,k-root->data,ans);

    solve(root->right,k-root->data,ans);


}
void checkeachnode(TreeNode<int> * root,int k,int& ans)
{
    if(root==NULL)
    return;

    solve(root,k,ans);
    //cout<<root->data<<" "<<ans<<endl;

    checkeachnode(root->left,k,ans);
    checkeachnode(root->right,k,ans);

}
int noWays(TreeNode < int > * root, int k) {
   if(root==NULL)
   {
       return 0;
   }
   int ans=0;
   checkeachnode(root,k,ans);
   return ans;
}