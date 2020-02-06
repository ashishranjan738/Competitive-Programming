#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int Solution::isMatch(const string A, const string B);
};

// Implement regular expression matching with support for '.' and '*'.

// '.' Matches any single character.
// '*' Matches zero or more of the preceding element.

// The matching should cover the entire input string (not partial).

// The function prototype should be:

// int isMatch(const char *s, const char *p)
// Some examples:

// isMatch("aa","a") → 0
// isMatch("aa","aa") → 1
// isMatch("aaa","aa") → 0
// isMatch("aa", "a*") → 1
// isMatch("aa", ".*") → 1
// isMatch("ab", ".*") → 1
// isMatch("aab", "c*a*b") → 1
// Return 0 / 1 ( 0 for false, 1 for true ) for this problem

// Solution 1: Top Down approach (recursion + memoization)
// bool solve(const string &a, const string &b, int i, int j, vector<vector<bool>> &dp, vector<vector<bool>> &visited)
// {
//     if (i >= a.length() && j >= b.length())
//         return 1;
//     if (i >= a.length())
//     {
//         if (j < b.length() - 1 && b[j + 1] == '*')
//             return solve(a, b, i, j + 2, dp, visited);
//         return 0;
//     }
//     if (j >= b.length())
//         return 0;
//     if (visited[i][j])
//         return dp[i][j];
//     bool ans = 0;
//     if (j < b.length() - 1 && b[j + 1] == '*')
//     {
//         if (b[j] == a[i] || b[j] == '.')
//             ans = ans || solve(a, b, i + 1, j + 2, dp, visited) || solve(a, b, i + 1, j, dp, visited);
//         ans = ans || solve(a, b, i, j + 2, dp, visited);
//     }
//     else if (a[i] == b[j] || b[j] == '.')
//         ans = ans || solve(a, b, i + 1, j + 1, dp, visited);
//     visited[i][j] = 1;
//     return dp[i][j] = ans;
// }

// int Solution::isMatch(const string A, const string B)
// {
//     vector<vector<bool>> visited(A.length(), vector<bool>(B.length(), 0));
//     vector<vector<bool>> dp(A.length(), vector<bool>(B.length(), 0));
//     return solve(A, B, 0, 0, dp, visited);
// }

// Solution 2: Bottom Up Approach (tabular)
int Solution::isMatch(const string A, const string B)
{
    vector<vector<bool>> dp(A.length() + 1, vector<bool>(B.length() + 1, 0));
    dp[0][0] = 1;
    for (int i = 1; i <= B.length(); i++)
        if (B[i - 1] == '*')
            dp[0][i] = dp[0][i - 2];
    for (int i = 1; i <= A.length(); i++)
    {
        for (int j = 1; j <= B.length(); j++)
        {
            if (B[j - 1] == '*')
            {
                dp[i][j] = dp[i][j] || dp[i][j - 2];
                if (B[j - 2] == A[i - 1] || B[j - 2] == '.')
                    dp[i][j] = dp[i][j] || dp[i - 1][j] || dp[i - 1][j - 2];
            }
            else if (A[i - 1] == B[j - 1] || B[j - 1] == '.')
                dp[i][j] = dp[i][j] || dp[i - 1][j - 1];
        }
    }
    return dp[A.length()][B.length()];
}