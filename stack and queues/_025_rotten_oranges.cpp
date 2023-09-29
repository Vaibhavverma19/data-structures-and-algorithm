#include<bits/stdc++.h>
int minTimeToRot(vector<vector<int>>& grid, int n, int m)
{
    int totalFresh=0;
    queue<pair<int,int> > q;
    for(int i=0;i<n;++i)
    {
        for(int j=0;j<m;++j)
        {
            if(grid[i][j]==1)
            {
                totalFresh++;
            }
            if(grid[i][j]==2)
            {
                q.push({i,j});
            }
        }
    } 
    if(totalFresh==0)
    {
        return 0;
    }
    int second=0;
    int cnt=0;
    while(!q.empty())
    {
        int size=q.size();
         second+=1;
         
        while(size--)
        {
           auto it=q.front();
           q.pop();
           int row=it.first;
           int col=it.second;

           //up
           if(row-1>=0 && grid[row-1][col]==1)
           {   cnt++;
               grid[row-1][col]=2;
               q.push({row-1,col});
           }

           //down row+1
           if(row+1<=n-1 && grid[row+1][col]==1)
           {   cnt++;
               grid[row+1][col]=2;
               q.push({row+1,col});
           }

           //left col-1;
           if(col-1>=0 && grid[row][col-1]==1)
           {   cnt++;
               grid[row][col-1]=2;
               q.push({row,col-1});
           }

           //right col+1
           if(col+1<=m-1 && grid[row][col+1]==1)
           {   cnt++;
               grid[row][col+1]=2;
               q.push({row,col+1});
           }
           
        }
    }
    if(cnt==totalFresh)
    {
        return second-1;
    }else{
        return -1;
    }
}