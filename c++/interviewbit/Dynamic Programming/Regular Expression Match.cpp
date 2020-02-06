#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int Solution::isMatch(const string A, const string B);
};

// Implement wildcard pattern matching with support for ‘?’ and ‘*’ for strings A and B.

// ’?’ : Matches any single character.
// ‘*’ : Matches any sequence of characters (including the empty sequence).
// The matching should cover the entire input string (not partial).

// Input Format:

// The first argument of input contains a string A.
// The second argument of input contains a string B.
// Output Format:

// Return 0 or 1:
//     => 0 : If the patterns do not match.
//     => 1 : If the patterns match.
// Constraints:

// 1 <= length(A), length(B) <= 9e4
// Examples :

// Input 1:
//     A = "aa"
//     B = "a"

// Output 1:
//     0

// Input 2:
//     A = "aa"
//     B = "aa"

// Output 2:
//     1

// Input 3:
//     A = "aaa"
//     B = "aa"

// Output 3:
//     0

// Input 4:
//     A = "aa"
//     B = "*"

// Output 4:
//     1

// Input 5:
//     A = "aa"
//     B = "a*"

// Output 5:
//     1

// Input 6:
//     A = "ab"
//     B = "?*"

// Output 6:
//     1

// Input 7:
//     A = "aab"
//     B = "c*a*b"

// Output 7:
//     0

// Solution 1: Top Down approach (recursion + memoization)
// bool solve(const string &a, const string &b, int i, int j, vector<vector<bool>> &dp, vector<vector<bool>> &visited)
// {
//     if (i >= a.length() && j >= b.length())
//         return true;
//     if (i >= a.length())
//     {
//         if (b[j] == '*')
//             return solve(a, b, i, j + 1, dp, visited);
//         else
//             return false;
//     }
//     if (j >= b.length())
//         return false;
//     if (visited[i][j])
//         return dp[i][j];
//     bool ans = false;
//     if ((a[i] == b[j] || b[j] == '?'))
//         ans = solve(a, b, i + 1, j + 1, dp, visited);
//     if (b[j] == '*')
//         ans = solve(a, b, i + 1, j, dp, visited) || solve(a, b, i + 1, j + 1, dp, visited) || solve(a, b, i, j + 1, dp, visited);
//     visited[i][j] = true;
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
    dp[0][0] = true;
    for (int i = 1; i <= B.length(); i++)
        if (B[i - 1] == '*')
            dp[0][i] = dp[0][i - 1];
    for (int i = 1; i <= A.length(); i++)
    {
        for (int j = 1; j <= B.length(); j++)
        {
            if (A[i - 1] == B[j - 1] || B[j - 1] == '?')
                dp[i][j] = dp[i - 1][j - 1];
            else if (B[j - 1] == '*')
                dp[i][j] = dp[i - 1][j] | dp[i - 1][j - 1] | dp[i][j - 1];
        }
    }
    return dp[A.length()][B.length()];
}
