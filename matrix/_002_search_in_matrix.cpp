#include <bits/stdc++.h> 
pair<int, int> search(vector<vector<int>> matrix, int x)
{
    int n=matrix.size();
    int m=matrix[0].size();
    int i=0;
    int j=m-1;
    while(i<n && j>=0)
    {
        //check whether the target is curr element?
        if(matrix[i][j]==x)
        {
            return {i,j};
        }
        
        //compare it with the curr element 
        if(x < matrix[i][j])
        {
            j--; //check in the same row but lower colms
        }else{
            //it is not in the curr row coz it is greater than the curr element
            //since we are checking from last col so we are sure that it is not present in the same row in further colms
            i++;
        }
    }

    return {-1,-1};
}