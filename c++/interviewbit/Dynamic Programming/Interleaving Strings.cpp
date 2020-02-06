#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int Solution::isInterleave(string A, string B, string C);
};

// Given A, B, C, find whether C is formed by the interleaving of A and B.

// Input Format:*

// The first argument of input contains a string, A.
// The second argument of input contains a string, B.
// The third argument of input contains a string, C.
// Output Format:

// Return an integer, 0 or 1:
//     => 0 : False
//     => 1 : True
// Constraints:

// 1 <= length(A), length(B), length(C) <= 150
// Examples:

// Input 1:
//     A = "aabcc"
//     B = "dbbca"
//     C = "aadbbcbcac"

// Output 1:
//     1

// Explanation 1:
//     "aa" (from A) + "dbbc" (from B) + "bc" (from A) + "a" (from B) + "c" (from A)

// Input 2:
//     A = "aabcc"
//     B = "dbbca"
//     C = "aadbbbaccc"

// Output 2:
//     0

// Explanation 2:
//     It is not possible to get C by interleaving A and B.

// Solution 1: Top Down approach (recursion + memoization)
// bool check(string &A, string &B, string &C, int i, int j, int k, vector<vector<vector<char>>> &dp)
// {
//     if (k >= C.length())
//         return 1;
//     if (dp[i][j][k] != -1)
//         return dp[i][j][k];
//     bool ans = false;
//     if (i < A.length() && A[i] == C[k])
//         ans = check(A, B, C, i + 1, j, k + 1, dp);

//     if (j < B.length() && B[j] == C[k] && !ans)
//         ans = check(A, B, C, i, j + 1, k + 1, dp);
//     return dp[i][j][k] = ans;
// }

// int Solution::isInterleave(string A, string B, string C)
// {
//     if (C.length() != A.length() + B.length())
//         return 0;
//     vector<vector<vector<char>>> dp(A.length() + 1, vector<vector<char>>(B.length() + 1, vector<char>(C.length() + 1, -1)));
//     return check(A, B, C, 0, 0, 0, dp);
// }

// Solution 2: Bottom Up Approach (tabular)
bool solve(string &a, string &b, string &c)
{
    if (a.length() + b.length() != c.length())
        return false;
    vector<vector<bool>> dp(a.length() + 1, vector<bool>(b.length() + 1, 0));
    dp[0][0] = 1;
    for (int i = 1; i <= a.length(); i++)
        if (a[i - 1] == c[i - 1])
            dp[i][0] = dp[i - 1][0];
    for (int i = 1; i <= b.length(); i++)
        if (b[i - 1] == c[i - 1])
            dp[0][i] = dp[0][i - 1];

    for (int i = 1; i <= a.length(); i++)
    {
        for (int j = 1; j <= b.length(); j++)
        {
            if (c[i + j - 1] == a[i - 1])
                dp[i][j] = dp[i][j] | dp[i - 1][j];
            if (c[i + j - 1] == b[j - 1])
                dp[i][j] = dp[i][j] | dp[i][j - 1];
        }
    }
    return dp[a.length()][b.length()];
}

int Solution::isInterleave(string A, string B, string C)
{
    return solve(A, B, C);
}