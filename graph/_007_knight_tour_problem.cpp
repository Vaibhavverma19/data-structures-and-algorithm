//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution 
{
    public:
    //Function to find out minimum steps Knight needs to reach target position.
    bool issafe(int x,int y,vector<vector<int> >& move,int& n)
    {
        if(x<0 || x>=n || y<0 || y>n-1 || move[x][y]>0)
         {
             return false;
         }
        return true;
    }
	int minStepToReachTarget(vector<int>&KnightPos,vector<int>&TargetPos,int N)
	{   int n=N;
	    int x[] = {1, 2, 1, 2, -1, -2, -1, -2};
	    int y[] = {2, 1, -2, -1, 2, 1, -2, -1};
	    
	    vector<vector<int> > moved(n,vector<int>(n,0));
	    int sx=KnightPos[0]-1;
	    int sy=KnightPos[1]-1;
	    int tx=TargetPos[0]-1;
	    int ty=TargetPos[1]-1;
	    if(sx==tx && sy==ty)
	    return 0;
	    
	   
	    queue<pair<int,int> > q;
	    q.push({sx,sy});
	    while(!q.empty())
	    {  //front nikalo
	        auto it=q.front();
	        q.pop();
	        
	        //uske saare possible next positions ko queue me daalo. agr safe hai to.
	        for(int i=0;i<8;++i)
	        {
	            int nx=it.first + x[i];
	            int ny=it.second + y[i];
	            
	            if(nx==tx && ny==ty)
	            {
	                return moved[it.first][it.second]+1;
	            }
	            if(issafe(nx,ny,moved,n))
	            {   
	                q.push({nx,ny});
	                //vis[nx][ny]=true;
	                moved[nx][ny]=1+moved[it.first][it.second];
	            }
	        }
	        
	    }
	    return moved[tx][ty];
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		vector<int>KnightPos(2);
		vector<int>TargetPos(2);
		int N;
		cin >> N;
		cin >> KnightPos[0] >> KnightPos[1];
		cin >> TargetPos[0] >> TargetPos[1];
		Solution obj;
		int ans = obj.minStepToReachTarget(KnightPos, TargetPos, N);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends