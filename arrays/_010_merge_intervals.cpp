#include <bits/stdc++.h>
/*

    intervals[i][0] = start point of i'th interval
    intervals[i][1] = finish point of i'th interval

*/
// bool comp(vector<int> a,vector<int> b){
//     return a[0]<b[0];
// }
vector<vector<int>> mergeIntervals(vector<vector<int>> &intervals)
{
    int n = intervals.size();
    sort(intervals.begin(), intervals.end()); //,comp);
    vector<vector<int>> ans;
    ans.push_back(intervals[0]);

    for (int i = 1; i < n; ++i)
    {
        if (ans.back()[1] >= intervals[i][0])
        {

            ans.back()[1] = max(ans.back()[1], intervals[i][1]);
        }
        else
        {

            ans.push_back(intervals[i]);
        }
    }

    return ans;
}
