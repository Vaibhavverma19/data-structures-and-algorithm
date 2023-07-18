class Solution {
public:
    vector<int> ans;
    void traverseleft(Node* root)
    {
        if(root==NULL)
        return;
        //if leaf node.
        if(root->left==NULL && root->right==NULL)
        {
            return;
        }
        ans.push_back(root->data);
        if(root->left)
        {
            traverseleft(root->left);
            
        }
        else{
            traverseleft(root->right);
        }
    }
    void traverseleaf(Node* root)
    {
        if(root==NULL)
        return;
        
        if(root->left==NULL && root->right==NULL)
        {
            ans.push_back(root->data);
            return;
        }
        
        traverseleaf(root->left);
        
        traverseleaf(root->right);
    }
    void traverseright(Node* root)
    {
        if(root==NULL)
        {
            return;
        }
        if(root->left==NULL && root->right==NULL)
        {
            return;
        }
        
       
        
        if(root->right)
        traverseright(root->right);
        else{
            traverseright(root->left);
        }
        
         ans.push_back(root->data);
    }
   
    vector <int> boundary(Node *root)
    {
        //iska basic logic hai ki hume
        //3 partme question ko break karna hai.
        //1. all left boundary elements except leaf node.
        //2. all leaf nodes
        //3. all right boundary nodes except leaf nodes and in reverse order.
        if(root==NULL)
        return ans;
       ans.push_back(root->data);
       
       traverseleft(root->left);
       
       traverseleaf(root->left);
       
       traverseleaf(root->right);
       
       traverseright(root->right);
        return ans;
    }
};