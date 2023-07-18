void solve(Node* root,int diag,map<int,vector<int> >& mapp,vector<int>& ans)
{
    if(root==NULL)
    {
        return;
    }
    
    mapp[diag].push_back(root->data);
    
    solve(root->left,diag+1,mapp,ans);
    
    solve(root->right,diag,mapp,ans);
}
vector<int> diagonal(Node *root)
{  vector<int> ans;
   map<int,vector<int> > mapp;
   solve(root,0,mapp,ans);
   for(auto i:mapp)
   {
       for(auto j:i.second)
       {
           ans.push_back(j);
       }
   }
   return ans;
   
}