#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int Solution::maxcoin(vector<int> &A);
};

// There are A coins (Assume A is even) in a line.

// Two players take turns to take a coin from one of the ends of the line until there are no more coins left.

// The player with the larger amount of money wins.

// Assume that you go first.

// Return the maximum amount of money you can win.

// Input Format:

// The first and the only argument of input contains an integer array, A.
// Output Format:

// Return an integer representing the maximum amount of money you can win.
// Constraints:

// 1 <= length(A) <= 500
// 1 <= A[i] <= 1e5
// Examples:

// Input 1:
//     A = [1, 2, 3, 4]

// Output 1:
//     6

// Explanation 1:

//     You      : Pick 4
//     Opponent : Pick 3
//     You      : Pick 2
//     Opponent : Pick 1

//     Total money with you : 4 + 2 = 6

// Input 2:
//     A = [5, 4, 8, 10]

// Output 2:
//     15

// Explanation 2:

//     You      : Pick 10
//     Opponent : Pick 8
//     You      : Pick 5
//     Opponent : Pick 4

//     Total money with you : 10 + 5 = 15

// Solution 1: Top Down approach (recursion + memoization)

// int solve(vector<int> &nums, int i, int j, vector<vector<int>> &dp)
// {
//     if (i > j)
//         return 0;
//     else if (i == j)
//         return nums[i];
//     else if (dp[i][j] != -1)
//         return dp[i][j];
//     return dp[i][j] = max(nums[i] + min(solve(nums, i + 2, j, dp), solve(nums, i + 1, j - 1, dp)), nums[j] + min(solve(nums, i + 1, j - 1, dp), solve(nums, i, j - 2, dp)));
// }

// int Solution::maxcoin(vector<int> &A)
// {
//     vector<vector<int>> dp(A.size(), vector<int>(A.size(), -1));
//     return solve(A, 0, A.size() - 1, dp);
// }

// Solution 2: Bottom Up Approach (tabular)

int Solution::maxcoin(vector<int> &A)
{
    vector<vector<int>> dp(A.size(), vector<int>(A.size(), 0));
    for (int gap = 1; gap < A.size(); gap++)
    {
        for (int i = 0, j = gap; j < A.size(); i++, j++)
        {
            int x = (gap >= 2) ? dp[i + 2][j] : 0;
            int y = dp[i + 1][j - 1];
            int z = (gap >= 2) ? dp[i][j - 2] : 0;
            dp[i][j] = max(A[i] + min(x, y), A[j] + min(y, z));
        }
    }
    return dp[0][A.size() - 1];
}
