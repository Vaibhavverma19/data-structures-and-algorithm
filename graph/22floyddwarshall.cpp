//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++
//************DRY RUNNNNNNNNN******************************************
class Solution {
  public:
	void shortest_distance(vector<vector<int>>&matrix){
	   for(int i=0;i<matrix.size();++i)
	   {
	       for(int j=0;j<matrix[0].size();++j)
	       {
	           if(matrix[i][j]==-1)
	           {
	               matrix[i][j]=1e6+7;
	           }
	           if(i==j)
	           matrix[i][j]=0;
	       }
	   }
	   for(int k=0;k<matrix.size();++k)
	   {
	       for(int i=0;i<matrix.size();++i)
	       {
	           for(int j=0;j<matrix.size();++j)
	           {
	               matrix[i][j]=min(matrix[i][j],matrix[i][k]+matrix[k][j]);
	           }
	       }
	   }
	   //for deetcting negative cycle 0->1(-2)->2(-2)->0(1)  so in thic case 0->0 will be -3 and ideally
	   //0->0 should always be 0.
	   
	   
	   for(int i=0;i<matrix.size();++i)
	   {
	       for(int j=0;j<matrix[0].size();++j)
	       {
	           if(matrix[i][j]==1e6+7)
	           {
	               matrix[i][j]=-1;
	           }
	           
	       }
	   }
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<vector<int>>matrix(n, vector<int>(n, -1));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				cin >> matrix[i][j];
			}
		}
		Solution obj;
		obj.shortest_distance(matrix);
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				cout << matrix[i][j] << " ";
			}
			cout << "\n";
		}
	}
	return 0;
}
// } Driver Code Ends