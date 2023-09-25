#include <bits/stdc++.h>
void heapify(int index, vector<int> &arr, int n)
{
    int largest = index;
    int left = 2 * index + 1;
    int right = 2 * index + 2;

    if (left < n && arr[largest] < arr[left])
    {
        largest = left;
    }
    if (right < n && arr[largest] < arr[right])
    {
        largest = right;
    }

    if (largest != index)
    {
        swap(arr[largest], arr[index]);
        heapify(largest, arr, n);
    }
}
void buildMinHeap(vector<int> &arr)
{
    int n = arr.size();
    for (int i = n / 2; i >= 0; --i)
    {
        heapify(i, arr, n);
        // it will take constant time approx kuki siftdown approach laga rhe hai
    }
    // therefore overall tc will be o(n).
}
vector<int> heapSort(vector<int> &arr, int n)
{
    buildMinHeap(arr);

    // now we have maxheap.
    int size = n;
    for (int index = n - 1; index >= 0; --index)
    {
        swap(arr[0], arr[index]);
        size--;
        heapify(0, arr, size);
    }

    return arr;
}