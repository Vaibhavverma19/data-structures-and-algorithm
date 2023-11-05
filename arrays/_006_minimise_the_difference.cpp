#include <bits/stdc++.h>
int minimizeIt(vector<int> A, int K)
{
    if (A.size() == 1)
    {
        return 0;
    }
    sort(A.begin(), A.end());
    int smallest = A[0] + K;
    int largest = A[A.size() - 1] - K;
    int diff = A[A.size() - 1] - A[0];

    for (int i = 1; i < A.size(); ++i)
    {
        if (A[i] - K >= 0)
        {
            int mini = min(smallest, A[i] - K);

            int maxi = max(largest, A[i - 1] + K);

            diff = min(diff, maxi - mini);
        }
    }
    // cout<<smallest<<"   "<<largest<<endl;
    return diff;
}