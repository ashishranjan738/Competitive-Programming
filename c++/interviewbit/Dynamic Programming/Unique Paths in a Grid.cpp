#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int Solution::uniquePathsWithObstacles(vector<vector<int>> &A);
};

// Given a grid of size m * n, lets assume you are starting at (1,1) and your goal is to reach (m,n). At any instance, if you are on (x,y), you can either go to (x, y + 1) or (x + 1, y).

// Now consider if some obstacles are added to the grids. How many unique paths would there be?
// An obstacle and empty space is marked as 1 and 0 respectively in the grid.

// Example :
// There is one obstacle in the middle of a 3x3 grid as illustrated below.

// [
//   [0,0,0],
//   [0,1,0],
//   [0,0,0]
// ]
// The total number of unique paths is 2.

//  Note: m and n will be at most 100.

// Solution 1: Top Down approach (recursion + memoization)

// int count(vector<vector<int>> &A, int i, int j)
// {
//     if (i < 0 || j < 0 || i >= A.size() || j >= A.front().size())
//         return 0;
//     else if (A[i][j])
//         return 0;
//     else if (i == A.size() - 1 && j == A.front().size() - 1)
//     {
//         return 1;
//     }
//     return count(A, i + 1, j) + count(A, i, j + 1);
// }

// int Solution::uniquePathsWithObstacles(vector<vector<int>> &A)
// {
//     return count(A, 0, 0);
// }

// Solution 2: Bottom Up Approach (tabular)

int Solution::uniquePathsWithObstacles(vector<vector<int>> &A)
{
    if (A.back().back())
        return 0;
    int n = A.size(), m = A.front().size();
    vector<vector<int>> dp(n, vector<int>(m, 0));
    dp[n - 1][m - 1] = 1;
    for (int i = n - 1; i >= 0; i--)
    {
        for (int j = m - 1; j >= 0; j--)
        {
            if (A[i][j])
                continue;
            dp[i][j] += ((i == n - 1) ? 0 : dp[i + 1][j]) + ((j == m - 1) ? 0 : dp[i][j + 1]);
        }
    }
    return dp[0][0];
}