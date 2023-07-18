//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct Node
{
	char data;
	struct Node *left;
	struct Node *right;

	Node(char x) {
		data = x;
		left = NULL;
		right = NULL;
	}
};

struct Node* buildTree(string str)
{
	// Corner Case
	if (str.length() == 0 || str[0] == 'N')
		return NULL;

	// Creating vector of strings from input
	// string after spliting by space
	vector<string> ip;

	istringstream iss(str);
	for (string str; iss >> str; )
		ip.push_back(str);

	// Create the root of the tree
	Node *root = new Node(stoi(ip[0]));

	// Push the root to the queue
	queue<Node*> queue;
	queue.push(root);

	// Starting from the second element
	int i = 1;
	while (!queue.empty() && i < ip.size()) {

		// Get and remove the front of the queue
		Node* currNode = queue.front();
		queue.pop();

		// Get the current node's value from the string
		string currVal = ip[i];

		// If the left child is not null
		if (currVal != "N") {

			// Create the left child for the current Node
			currNode->left = new Node(stoi(currVal));

			// Push it to the queue
			queue.push(currNode->left);
		}

		// For the right child
		i++;
		if (i >= ip.size())
			break;
		currVal = ip[i];

		// If the right child is not null
		if (currVal != "N") {

			// Create the right child for the current node
			currNode->right = new Node(stoi(currVal));

			// Push it to the queue
			queue.push(currNode->right);
		}
		i++;
	}

	return root;
}


// } Driver Code Ends
/*The structure of the Binary Tree Node  is
struct Node
{
  char data;
  struct Node* left;
  struct Node* right;
};*/

class Solution {
  public:
    /*This function returns true if the tree contains 
    a duplicate subtree of size 2 or more else returns false*/
    bool solve(Node* x,Node* y,int flag)
    {
        if(x==NULL && y==NULL)
        return true;
        
        if(x==NULL || y==NULL)
        return false;
        
        //case for leaf node.
        //if they are same  but level is not 0 then only consider it as true.
        if(x->left==NULL && x->right==NULL && y->left==NULL && y->right==NULL )
        {
            if(x->data==y->data && flag>0)
            {
                return true;
            }
            else{
                return false;
            }
        }
        
        //if the two general nodes matched.
        //it is compulsry that both of their left and right must be the same in order to be
        //the duplicate sub tree.
        if(x->data==y->data)
        {
            bool left=solve(x->left,y->left,flag+1);
            bool right=solve(x->right,y->right,flag+1);
            
            return left && right;
        }
        
        bool op1=solve(x->left,y,0);
        bool op2=solve(x->right,y,0);
        bool op3=solve(x,y->left,0);
        bool op4=solve(x,y->right,0);
        
        return op1 || op2 || op3 || op4;
    }
    int dupSub(Node *root) {
        int cnt=0;
        
        if(root==NULL)
        return 0;
        if(root->left==NULL && root->right==NULL)
        return 0;
        bool ans=solve(root->left,root->right,cnt);
        if(ans)
        return 1;
        else return 0;
    }
};

//{ Driver Code Starts.

int main()
{
	
	int t;
	cin >> t;
	//cout << t << "\n";
	while (t--)
	{
		string treeString;
		getline(cin >> ws, treeString);
		struct Node* root = buildTree(treeString);
		Solution ob;
		cout << ob.dupSub(root) << "\n";
	}
	return 0;
}
// } Driver Code Ends