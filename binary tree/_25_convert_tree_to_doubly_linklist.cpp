// This function should return head to the DLL
class Solution
{
    public: 
    //Function to convert binary tree to doubly linked list and return it.
    Node * bToDLL(Node *root)
    {
        if(root==NULL)
        return NULL;
        
        if(root->left==NULL && root->right==NULL)
        {
            return root;
        }
        
        Node* left_head=bToDLL(root->left);
        
        Node* right_head=bToDLL(root->right);
        
        while(left_head!=NULL && left_head->right!=NULL)
        {
            left_head=left_head->right;
        }
        
        root->left=left_head;
        root->right=right_head;
        
        if(left_head!=NULL)
        left_head->right=root;
        
        if(right_head!=NULL)
        right_head->left=root;
        
        while(root->left!=NULL)
        root=root->left;
        
        return root;
        
        
    }
};


//optimised code
 private:
        Node *prev=NULL,*head=NULL;
    public:    
        void BinTODLL(Node *root) {
            if(!root) return ;
            BinTODLL(root->left);
            if(prev == NULL ){
                head = root;
                prev = root;
            }
            else {
                prev->right = root;
                root->left = prev;
                prev = root;
            }
            BinTODLL(root->right);
        }
        Node * bToDLL(Node *root){
            BinTODLL(root);
            return head;
        }
