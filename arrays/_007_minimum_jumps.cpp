int minimumJumps(vector<int> &arr, int n)
{
    if (n == 1)
    {
        return 0;
    }
    int farthest = 0;
    int jumps_completed = 0;
    int thisJumpLimit = 0;
    for (int i = 0; i < n; ++i)
    {
        if (i > farthest)
        {

            return -1;
        }

        if (i == n - 1)
        {
            // no need to process further
            return jumps_completed;
        }

        // how much far we can go from this element? i+arr[i]
        // if this is farthest then update it.
        farthest = max(farthest, i + arr[i]);

        // limit reached?
        // agar saari possibility check kr li to jump kar do or new limit batao
        if (i == thisJumpLimit)
        {
            jumps_completed++;
            thisJumpLimit = farthest;
        }
    }
    return jumps_completed;
}