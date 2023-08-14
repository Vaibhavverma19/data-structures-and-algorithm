#include <bits/stdc++.h> 
void solve(vector < vector < int >> & arr, int n,vector<string>& ans,string& str,vector<vector<bool> >& vis,int i,int j)
{
     if(i<0 || i>=n || j<0 || j>=n || vis[i][j]==true || arr[i][j]==0 )
     {
         return;
     }
      if(i==n-1 && j==n-1)
      {
          ans.push_back(str);
      }
     vis[i][j]=true;

    
     
     //down call
     
         str.push_back('D');
         solve(arr,n,ans,str,vis,i+1,j);
         str.pop_back();
     
     //left call
     
         str.push_back('L');
         solve(arr,n,ans,str,vis,i,j-1);
         str.pop_back();
     
     //right call
    
         str.push_back('R');
         solve(arr,n,ans,str,vis,i,j+1);
         str.pop_back();

      //up call
    
         str.push_back('U');
         solve(arr,n,ans,str,vis,i-1,j);
         str.pop_back();
     
     
    

    vis[i][j]=false;

}
vector < string > searchMaze(vector < vector < int >> & arr, int n) {
    vector<string> ans;
    string str="";
    vector<vector<bool> > vis(n,vector<bool>(n,false));
    solve(arr,n,ans,str,vis,0,0);
    return ans;
}