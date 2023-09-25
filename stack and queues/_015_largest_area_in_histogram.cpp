#include <bits/stdc++.h>
void findprevsamller(vector<int> &prevsmall, vector<int> &heights)
{
    stack<int> st;
    //  st.push(-1);
    for (int i = 0; i < heights.size(); ++i)
    {
        while (!st.empty() && heights[i] <= heights[st.top()])
        {
            st.pop();
        }

        if (st.empty())
        {
            prevsmall[i] = -1;
        }
        else
        {

            prevsmall[i] = st.top();
        }
        st.push(i);
    }
}
void findnextsamller(vector<int> &nextsmall, vector<int> &heights)
{
    stack<int> st;
    //  st.push(-1);
    for (int i = heights.size() - 1; i >= 0; --i)
    {
        while (!st.empty() && heights[i] <= heights[st.top()])
        {
            st.pop();
        }

        if (st.empty())
        {
            nextsmall[i] = heights.size();
        }
        else
        {

            nextsmall[i] = st.top();
        }
        st.push(i);
    }
}
int largestRectangle(vector<int> &heights)
{
    vector<int> prevsmall(heights.size());
    vector<int> nextsmall(heights.size());
    findprevsamller(prevsmall, heights);
    findnextsamller(nextsmall, heights);

    int maxi = INT_MIN;

    for (int i = 0; i < heights.size(); ++i)
    {
        int area = (nextsmall[i] - prevsmall[i] - 1) * heights[i];
        maxi = max(maxi, area);
    }

    return maxi;
}