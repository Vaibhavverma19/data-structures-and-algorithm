//if you want to print then add necessary conditions for null pointers stored in the queue
//which will separate the different levels.

/* A binary tree Node

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
    
    Node(int x){
        data = x;
        left = right = NULL;
    }
};
 */


class Solution
{
    public:
    //Function to return the level order traversal of a tree.
    vector<int> levelOrder(Node* node)
    { vector<int> lot(0);
        if(node==NULL)
        return lot;
      queue<Node*> q;
      q.push(node);
      while(!q.empty())
      {
          Node* front=q.front();
          q.pop();
       
        lot.push_back(front->data);
        if(front->left!=NULL)
        q.push(front->left);
        if(front->right!=NULL)
        q.push(front->right);
          
          
      }
      return lot;
    }
};





// } Driver Code Ends