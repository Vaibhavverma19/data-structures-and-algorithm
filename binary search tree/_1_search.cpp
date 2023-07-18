bool search(Node* root, int x) {
   if(root==NULL)
   return false;
   
   if(root->data==x)
   return true;
   bool ans=false;
   if(root->data>x)
   {
       //left subtree.
       ans=search(root->left,x);
   }else{
       ans=search(root->right,x);
   }
   return ans;
}