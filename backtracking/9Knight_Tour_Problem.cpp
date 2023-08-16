#include <bits/stdc++.h> 

bool issafe(int x,int y,vector<vector<int> >& board,int n,int m)
{
    if(x<0 || x>=n || y<0 || y>=m || board[x][y]!=-1)
    {
        return false;
    }
    return true;
}
bool solve(int& n,int& m,vector<vector<int> >& board,int x[],int y[],int step,int currX,int currY)
{
     if(step==n*m)
     return true;

     for(int i=0;i<8;++i)
     {  int newX=currX+x[i];
        int newY=currY+y[i];
         if(issafe(newX,newY,board,n,m))
         {
             board[newX][newY]=step;
             //filled[newX][newY]=1;
             bool gotAns=solve(n,m,board,x,y,step+1,newX,newY);
             if(gotAns)
             return true;

             board[newX][newY]=-1;
             //filled[newX][newY]=0;
         }
     }

     return false;
}
vector<vector<int>> knightTour(int n, int m) {
    /* 
        Return matrix of size n*m where integer
        at cell(i, j) represent move number of knight to reach that
        cell. Move number start from 0.

        It may be possible that there is no possible order to visit each cell
        exactly once. In that case, return a matrix of size n*m having all the values
        equal to -1.
    */

   vector<vector<int> > board(n,vector<int>(m,-1));
   //vector<vector<int> > filled(n,vector<int>(m,0));
   int x[]={2,1,-1,-2,-2,-1,1,2};
   int y[]={1,2,2,1,-1,-2,-2,-1};
   board[0][0]=0;
   bool gotAns=solve(n,m,board,x,y,1,0,0);
   if(!gotAns)
   {
       board[0][0]=-1;
   }
   return board;
   
}