void solve(Node* root,vector<int>& ans,int level)
{
    if(root==NULL)
    return;
    //on observing it is clear that we have to print the first element of each level.
    //so track level and print only that node which is following this condition.
    if(level==ans.size())
    {
        ans.push_back(root->data);
    }
    solve(root->left,ans,level+1);
    solve(root->right,ans,level+1);
    
    
}
vector<int> leftView(Node *root)
{
   vector<int> ans(0);
  solve(root,ans,0);
  return ans;
}