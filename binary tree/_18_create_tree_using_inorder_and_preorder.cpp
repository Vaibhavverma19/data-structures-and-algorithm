//{ Driver Code Starts
//

#include<bits/stdc++.h>
using namespace std;

struct Node
{
	int data;
	struct Node *left;
	struct Node *right;
	
	Node(int x){
	    data = x;
	    left = NULL;
	    right = NULL;
	}
};


void printPostOrder(Node *root)
{
	if(root==NULL)
		return;
	printPostOrder(root->left);
	printPostOrder(root->right);
	cout<<root->data<<" ";
}

// } Driver Code Ends

/*Complete the code here.
Node is as follows:
struct Node
{
  int data;
  Node* left;
  Node* right;
};
*/
class Solution{
    public:
    int position(int in[],int n,int target,int start,int end)
    {   int i;
        for( i=start;i<=end;++i)
        {
            if(target==in[i])
            return i;
        }
        return i;
    }
    Node* solve(int in[],int pre[],int& preindex,int start,int end,int n)
    {
        if(preindex>=n || start>end)
        return NULL;
        
        Node* newnode=new Node(pre[preindex]);
        
        int pos=position(in,n,pre[preindex],start,end);
        preindex+=1;
        
        newnode->left=solve(in,pre,preindex,start,pos-1,n);
        
        newnode->right=solve(in,pre,preindex,pos+1,end,n);
        
        return newnode;
    }
    Node* buildTree(int in[],int pre[], int n)
    {int preindex=0;
        Node* root=solve(in,pre,preindex,0,n-1,n);
        return root;
    }
};

//{ Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		
		int inorder[n], preorder[n];
		for(int i=0; i<n; i++)
			cin>> inorder[i];
		for(int i=0; i<n; i++)
			cin>> preorder[i];
		Solution obj;
		Node *root = obj.buildTree(inorder, preorder, n);
		printPostOrder(root);
		cout<< endl;
	}
}

// } Driver Code Ends