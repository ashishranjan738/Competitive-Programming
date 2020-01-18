#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int Solution::largestRectangleArea(vector<int> &A);
};

// Given an array of integers A of size N. A represents a histogram i.e A[i] denotes height of
// the ith histogram’s bar. Width of each bar is 1.

// http://i.imgur.com/1OutEEI.png

// Largest Rectangle in Histogram: Example 1

// Above is a histogram where width of each bar is 1, given height = [2,1,5,6,2,3].

// http://i.imgur.com/F2bePvG.png

// Largest Rectangle in Histogram: Example 2

// The largest rectangle is shown in the shaded area, which has area = 10 unit.

// Find the area of largest rectangle in the histogram.

// Input Format

// The only argument given is the integer array A.
// Output Format

// Return the area of largest rectangle in the histogram.
// For Example

// Input 1:
//     A = [2, 1, 5, 6, 2, 3]
// Output 1:
//     10
//     Explanation 1:
//         The largest rectangle is shown in the shaded area, which has area = 10 unit.

int maxAreaFromHistogram(vector<int> &v)
{
    int i = 0, maxArea = 0;
    stack<int> st;
    while (i < v.size())
    {
        if (st.empty() || v[i] >= v[st.top()])
            st.push(i++);
        else
        {
            int top = st.top();
            st.pop();
            maxArea = max(maxArea, v[top] * (st.empty() ? i : i - 1 - st.top()));
        }
    }
    while (!st.empty())
    {
        int top = st.top();
        st.pop();
        maxArea = max(maxArea, v[top] * (st.empty() ? i : i - 1 - st.top()));
    }
    return maxArea;
}

int Solution::largestRectangleArea(vector<int> &A)
{
    return maxAreaFromHistogram(A);
}
