class Solution
{   vector<int> ans;
    public:
    //Function to return a list of nodes visible from the top view 
    //from left to right in Binary Tree.
    void solve(Node* root)
    {
        //level order traversal karna padega ni to niche vala element  phle aa jayega .
        
        
        queue<pair<Node*,int> > q; //level order traversal ke liye
        
        map<int,int> map;  //line or uske sath konsi node usme hai vo track karne keliye.
        
        q.push({root,0});
        
        while(!q.empty())
        {
            auto temp=q.front();
            q.pop();
            
            
            Node* node=temp.first;
            int line=temp.second;
            
            
            //chech if line is already occupied or not? if it is present in map or not?
            if(map.find(line)==map.end())
            {
                map[line]=node->data;
            }
            
            
            //ab node ke dono bacche queue me dal do.
            if(node->left!=NULL)
            q.push({node->left,line-1});
            
            if(node->right!=NULL)
            q.push({node->right,line+1});
            
        }
        
        for(auto i:map)
        {
            ans.push_back(i.second);
        }
    }
    vector<int> topView(Node *root)
    {
        solve(root);
        return ans;
    }

};