bool issafe(int i,int j,int n,int m)
{
    if(i<n && j<m && i>=0 && j>=0)
    {
        return true;
    }
    return false;
}
void solvefurther(string grid[], int n, int m, string& word,int cnt,int &ans,int i,int j,int rc,int cc)
{
    if(cnt==word.length()) 
    {
        ans++;
        return;
    }
   
    if(issafe(i+rc,j+cc,n,m) && grid[i+rc][j+cc]==word[cnt]  )
    {
        solvefurther(grid,n,m,word,cnt+1,ans,i+rc,j+cc,rc,cc);
    }
    
}
void solve(string grid[], int n, int m, string& word,int cnt,int &ans,int i,int j)
{
    

    int row[]={0,-1,-1,-1,0,1,1,1};
    int col[]={-1,-1,0,1,1,1,0,-1};

    for(int k=0;k<8;++k)
    {
        if(issafe(i+row[k],j+col[k],n,m) && grid[i+row[k]][j+col[k]]==word[cnt]  )
        {
            solvefurther(grid,n,m,word,cnt+1,ans,i+row[k],j+col[k],row[k],col[k]);
        }
    }
}
int wordSearch(string grid[], int n, int m, string word) {


     int ans=0;
    for(int i=0;i<n;++i)
   {
      for(int j=0;j<m;++j)
      {if(grid[i][j]==word[0])
        solve(grid,n,m,word,1,ans,i,j);
      }
   }
     return ans;
}