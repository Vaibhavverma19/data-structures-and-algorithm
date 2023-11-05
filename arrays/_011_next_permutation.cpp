#include <bits/stdc++.h>
vector<int> nextPermutation(vector<int> &permutation, int n)
{
    // find the first dip. after which sequence should be strictly decreasing till te end.
    int index = -1;
    for (int i = n - 2; i >= 0; --i)
    {
        if (permutation[i] < permutation[i + 1])
        {
            index = i;
            break;
        }
    }
    // koi ni mila
    if (index == -1)
    {
        reverse(permutation.begin(), permutation.end());
        return permutation;
    }

    // find the least possible.
    for (int j = n - 1; j > index; --j)
    {
        if (permutation[j] > permutation[index])
        {
            // replacement found
            swap(permutation[j], permutation[index]);
            break;
        }
    }

    // now we want the shortest possible number from the remaining elements
    // sort bad ke elements
    sort(permutation.begin() + index + 1, permutation.end());

    return permutation;
}