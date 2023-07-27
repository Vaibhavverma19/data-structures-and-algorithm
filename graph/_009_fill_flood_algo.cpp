class Solution {
public:
   bool issafe(vector<vector<int>>& image, int sr, int sc)
   {
       if(sr<0 || sr>=image.size() || sc<0 || sc>=image[0].size())
          return false;
       else return true;
   }
   void solvedfs(vector<vector<int>>& image, int sr, int sc, int& color,map<pair<int,int>,bool> &vis)
   {   
        
       vis[{sr,sc}]=true;
       //up
       if(vis[{sr-1,sc}]!=true )
       {   if(issafe(image,sr-1,sc))
           {  if(image[sr-1][sc]==image[sr][sc])
              solvedfs(image,sr-1,sc,color,vis);
           }
       }
       //down
       if(vis[{sr+1,sc}]!=true)
       {  if(issafe(image,sr+1,sc))
            {   if(image[sr+1][sc]==image[sr][sc])
                solvedfs(image,sr+1,sc,color,vis);
            }
       }
       //left
       if(vis[{sr,sc-1}]!=true)
       {   if(issafe(image,sr,sc-1)){
           if(image[sr][sc-1]==image[sr][sc])
           solvedfs(image,sr,sc-1,color,vis);
       }
       }
       //right
       if(vis[{sr,sc+1}]!=true)
       {   if(issafe(image,sr,sc+1))
          { if(image[sr][sc+1]==image[sr][sc])
           solvedfs(image,sr,sc+1,color,vis);
          }
       }

       image[sr][sc]=color;
       

   }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        map<pair<int,int>,bool> vis;
        solvedfs(image,sr,sc,color,vis);
        return image;

    }
};