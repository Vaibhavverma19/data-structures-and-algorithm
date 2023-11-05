
#include <bits/stdc++.h>

void rearrange(vector<int> &arr)
{
    int neg = 0;
    int n = arr.size();
    int pos = arr.size() - 1;
    while (neg <= pos)
    {
        if (arr[pos] >= 0 && arr[neg] >= 0)
            pos--;
        else if (arr[pos] < 0 && arr[neg] < 0)
            neg++;
        else if (arr[pos] < 0)
        {
            swap(arr[neg], arr[pos]);
            pos--;
            neg++;
        }
        else
        {
            pos--;
            neg++;
        }
    }
    if (neg == n - 1 || pos == 0)
    {
        return;
    }

    int i = 1;
    int j = pos + 1;
    while (i < arr.size() && j < arr.size())
    {
        swap(arr[i], arr[j]);
        i = i + 2;
        j++;
    }
}
