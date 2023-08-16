//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
// UNASSIGNED is used for empty cells in sudoku grid 
#define UNASSIGNED 0  

// N is used for the size of Sudoku grid.  
// Size will be NxN  
#define N 9  


// } Driver Code Ends

  #include <unordered_map>
class Solution 
{
    public:
    bool issafe(int num,map<pair<int,int>,bool>& visrownum,
       map<pair<int,int>,bool>& viscolnum,
       map<pair<int,int>,bool>& visblock,int row,int col)
       {   int block=(row/3)*3 + col/3;
           if(visrownum[{row,num}]==true || viscolnum[{col,num}]==true || visblock[{block,num}]==true)
           {
               return false;
           }
           
           return true;
       }
       
       
       
       
    bool solve(int grid[N][N],map<pair<int,int>,bool>& visrownum,
      map<pair<int,int>,bool>& viscolnum,
       map<pair<int,int>,bool>& visblock)
       {
           for(int i=0;i<N;++i)
           {
              for(int j=0;j<N;++j)
              {
                  if(grid[i][j]==0)
                  {
                      for(int num=1;num<=9;++num)
                      {
                          if(issafe(num,visrownum,viscolnum,visblock,i,j))
                          {
                              grid[i][j]=num;
                              visrownum[{i,num}]=true;
                              viscolnum[{j,num}]=true;
                              visblock[{(i/3)*3 + j/3,num}]=true;
                              bool dowegotans=solve(grid,visrownum,viscolnum,visblock);
                              
                              if(dowegotans==true)
                              return true;
                              else{
                              grid[i][j]=0;
                              visrownum[{i,num}]=false;
                              viscolnum[{j,num}]=false;
                              visblock[{(i/3)*3 + j/3,num}]=false;
                                  
                              }
                          }
                      }
                      
                      return false;
                  }
              }
           }
           
           return true;
       }
    //Function to find a solved Sudoku. 
    bool SolveSudoku(int grid[N][N])  
       
    { 
       map<pair<int,int>,bool> visrownum;
      map<pair<int,int>,bool> viscolnum;
      map<pair<int,int>,bool> visblock;
       
       for(int i=0;i<N;++i)
       {
           for(int j=0;j<N;++j)
           {
               if(grid[i][j]!=0)
               {
                   auto p1=make_pair(i,grid[i][j]);
                   auto p2=make_pair(j,grid[i][j]);
                   
                   visrownum[make_pair(i,grid[i][j])]=true;
                   viscolnum[make_pair(j,grid[i][j])]=true;
                   
                   //block 
                   int block=(i/3)*3 + j/3;
                   auto p3=make_pair(block,grid[i][j]);
                   visblock[make_pair(block,grid[i][j])]=true;
               }
           }
       }
       
       return solve(grid,visrownum,viscolnum,visblock);
       
       
       
       
    }
    
    //Function to print grids of the Sudoku.
    void printGrid (int grid[N][N]) 
    {
         for(int i=0;i<N;++i)
       {
           for(int j=0;j<N;++j)
           {
               cout<<grid[i][j]<<" ";
           }
           //cout<<endl;
       }
    }
};

//{ Driver Code Starts.

int main() {
	int t;
	cin>>t;
	while(t--)
	{
		int grid[N][N];
		
		for(int i=0;i<9;i++)
		    for(int j=0;j<9;j++)
		        cin>>grid[i][j];
		        
		Solution ob;
		
		if (ob.SolveSudoku(grid) == true)  
            ob.printGrid(grid);  
        else
            cout << "No solution exists";  
        
        cout<<endl;
	}
	
	return 0;
}
// } Driver Code Ends