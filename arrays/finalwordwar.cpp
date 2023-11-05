#include <bits/stdc++.h>
using namespace std;
bool definitelysmallerThan(float a, float b, float epsilon = FLT_EPSILON)
{
    return (b - a) > ((fabs(a) < fabs(b) ? fabs(b) : fabs(a)) * epsilon);
}
float solve(vector<float> &pw, vector<int> &imp, float &threshold, int index, float &total)
{
    if (index == pw.size())
    {
        return 0;
    }

    double ans1 = 0, ans2 = 0;
    // win
    total += (1 - pw[index]);
    float peb = max(total / (index + 1), 0.0f);

    if (definitelysmallerThan(peb, threshold))
    {

        ans1 = imp[index] + solve(pw, imp, threshold, index + 1, total);
    }

    total -= (1 - pw[index]); // backtrack

    // loose
    total -= pw[index];
    peb = max(total / (index + 1), 0.0f);
    if (definitelysmallerThan(peb, threshold))
    {

        ans2 = solve(pw, imp, threshold, index + 1, total);
    }
    total += pw[index]; // backtrack

    return max(ans1, ans2);
}
int main()
{
    vector<float> pw;
    vector<int> imp;
    pw.push_back(0.28);
    pw.push_back(0.62);
    pw.push_back(0.92);
    pw.push_back(0.96);

    imp.push_back(3);
    imp.push_back(8);
    imp.push_back(7);
    imp.push_back(2);

    float threshold = 0.05;
    float total = 0;
    cout << "ans: " << solve(pw, imp, threshold, 0, total);
}