//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    // Function to merge the arrays.
    void merge(long long arr1[], long long arr2[], int n, int m)
    {
        int i = n - 1;
        int j = 0;
        // we are going to separate the total n smaller elements in arr1 and m larger
        // elements in arr2
        while (i >= 0 && j < m)
        {
            if (arr1[i] >= arr2[j])
            {
                swap(arr1[i], arr2[j]);
                i--;
                j++;
            }
            else
            {
                // now if we reduce i we get lower num and inc j we get higher
                // and since now only arr2[j]> arr1[i] so further they will surely be the same
                break;
            }
        }

        // now their order can be different because bwe just separated them we have not align
        // them in proper order so
        sort(arr1, arr1 + n);
        sort(arr2, arr2 + m);
    }
};

//{ Driver Code Starts.

int main()
{

    int T;
    cin >> T;

    while (T--)
    {
        int n, m;
        cin >> n >> m;

        long long arr1[n], arr2[m];

        for (int i = 0; i < n; i++)
        {
            cin >> arr1[i];
        }

        for (int i = 0; i < m; i++)
        {
            cin >> arr2[i];
        }
        Solution ob;
        ob.merge(arr1, arr2, n, m);

        for (int i = 0; i < n; i++)
            cout << arr1[i] << " ";

        for (int i = 0; i < m; i++)
            cout << arr2[i] << " ";

        cout << endl;
    }

    return 0;
}

// } Driver Code Ends