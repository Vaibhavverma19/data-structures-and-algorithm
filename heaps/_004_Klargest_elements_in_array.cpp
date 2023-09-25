#include <queue>

vector<int> Klargest(vector<int> &arr, int k, int n) 
{
    // It will store K largest element
    vector<int> answer(k);

    // Min Heap using priority queue
    priority_queue<int, vector<int>, greater<int>> pq;
    
    // Add first K elements in min heap
    for (int i = 0; i < k; ++i) 
    {
        pq.push(arr[i]);
    }
    
    // Check for remaining elements
    for (int i = k; i < n; ++i) 
    {
        int top = pq.top();
        
        // If top is less than current element then delete top and add current element
        if (top < arr[i]) 
        {
            pq.pop();
            pq.push(arr[i]);
        }
    }
    
    // Putting K largest element in answer
    for (int j = 0; j < k; ++j) 
    {
        answer[j] = pq.top();
        pq.pop();
    }
    
    return answer;
}