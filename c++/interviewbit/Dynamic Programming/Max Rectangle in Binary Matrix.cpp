#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int Solution::maximalRectangle(vector<vector<int>> &A);
};

// Given a 2D binary matrix filled with 0’s and 1’s, find the largest rectangle containing all ones and return its area.

// Bonus if you can solve it in O(n^2) or less.

// Example :

// A : [  1 1 1
//        0 1 1
//        1 0 0
//     ]

// Output : 4

// As the max area rectangle is created by the 2x2 rectangle created by (0,1), (0,2), (1,1) and (1,2)

// Function to calculate the maximum area from histogram
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

int Solution::maximalRectangle(vector<vector<int>> &A)
{
    // converting the binary matrix to histogram by counting the number consecutive
    // 1s in the column
    for (int j = 0; j < A.front().size(); j++)
        for (int i = 1; i < A.size(); i++)
            if (A[i][j])
                A[i][j] += A[i - 1][j];

    int maxArea = 0;
    // calculating the maxArea from the converted histogram
    for (vector<int> &v : A)
        maxArea = max(maxArea, maxAreaFromHistogram(v));
    return maxArea;
}
