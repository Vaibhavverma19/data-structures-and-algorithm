#include <bits/stdc++.h> 

vector<int> spiralPathMatrix(vector<vector<int>> matrix, int n, int m) 

{

    

    int idx = 0;

    int total = n * m;

    int count = 0;

 

    int startingRow = 0;

    int startingCol = 0;

    int endingRow = n - 1;

    int endingCol = m - 1;

    vector<int> ans;

 

    while (count < total) {

 

        //Printing the first row

        for(idx = startingCol; idx <= endingCol && count < total; idx++) {

 

            ans.push_back(matrix[startingRow][idx]);

            count++;

 

        }

 

        startingRow++;

 

        //Printing the last col

        for (idx = startingRow; idx <= endingRow && count < total; idx++) {

 

            ans.push_back(matrix[idx][endingCol]);

            count++;

 

        }

 

        endingCol--;

 

        //Printing the last row

        for (idx = endingCol; idx >= startingCol && count < total; idx--) {

 

            ans.push_back(matrix[endingRow][idx]);

            count++;

 

        }

 

        endingRow--;

 

        //Printing the first col

        for (idx = endingRow; idx >= startingRow && count < total; idx--) {

 

            ans.push_back(matrix[idx][startingCol]);

            count++;

 

        }

 

        startingCol++;

 

    }

 

    return ans;

 

}