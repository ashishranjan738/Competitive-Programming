#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int Solution::isScramble(const string A, const string B);
};

// Given a string A, we may represent it as a binary tree by partitioning it to two non-empty substrings recursively.

// Below is one possible representation of A = “great”:

//     great
//    /    \
//   gr    eat
//  / \    /  \
// g   r  e   at
//            / \
//           a   t

// To scramble the string, we may choose any non-leaf node and swap its two children.

// For example, if we choose the node “gr” and swap its two children, it produces a scrambled string “rgeat”.

//     rgeat
//    /    \
//   rg    eat
//  / \    /  \
// r   g  e   at
//            / \
//           a   t
// We say that “rgeat” is a scrambled string of “great”.

// Similarly, if we continue to swap the children of nodes “eat” and “at”, it produces a scrambled string “rgtae”.

//     rgtae
//    /    \
//   rg    tae
//  / \    /  \
// r   g  ta  e
//        / \
//       t   a
// We say that “rgtae” is a scrambled string of “great”.

// Given two strings A and B of the same length, determine if B is a scrambled string of S.

// Input Format:

// The first argument of input contains a string A.
// The second argument of input contains a string B.
// Output Format:

// Return an integer, 0 or 1:
//     => 0 : False
//     => 1 : True
// Constraints:

// 1 <= len(A), len(B) <= 50
// Examples:

// Input 1:
//     A = "we"
//     B = "we"

// Output 1:
//     1

// Input 2:
//     A = "phqtrnilf"
//     B = "ilthnqrpf"

// Output 2:
//     0

// Solution 1: Top Down approach (recursion + memoization)
// bool solve(string a, string b, unordered_map<string, bool> &m)
// {
//     string key = a + " " + b;
//     if (m.count(key))
//         return m[key];
//     if (a == b)
//         return true;
//     int n = a.length();
//     bool res = false;
//     for (int i = 1; i < n && !res; i++)
//     {
//         // taking the first half and second half of both string 1 and string 2
//         res = res || (solve(a.substr(0, i), b.substr(0, i), m) && solve(a.substr(i, n - i), b.substr(i, n - i), m));
//         // taking the first half of string 1 and second half of string2
//         res = res || (solve(a.substr(0, i), b.substr(n - i, i), m) && solve(a.substr(i, n - i), b.substr(0, n - i), m));
//     }
//     return m[key] = res;
// }

// int Solution::isScramble(const string A, const string B)
// {
//     unordered_map<string, bool> m;
//     return solve(A, B, m);
// }

// Solution 2: Bottom Up Approach (tabular)
// We can use bottom-up DP to improve the performance, which is O(N^4) complexity. Here we build a table dp[len][i][j],
// which indicates whether s1[i..i+len-1] is a scramble of s2[j..j+len-1].

int Solution::isScramble(const string a, const string b)
{
    if (a.length() == 0 || a == b)
        return true;
    int n = a.length();
    int dp[n + 1][n][n];
    memset(dp, 0, sizeof(dp));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            dp[1][i][j] = a[i] == b[j];

    for (int len = 2; len <= n; len++)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                for (int k = 1; k < n && !dp[len][i][j]; k++)
                {
                    dp[len][i][j] = dp[len][i][j] || (dp[k][i][j] && dp[len - k][i + k][j + k]);
                    dp[len][i][j] = dp[len][i][j] || (dp[k][i + len - k][j] && dp[len - k][i][j + k]);
                }
            }
        }
    }
    return dp[n][0][0];
}

// Reference:
// https://leetcode.com/problems/scramble-string/discuss/29394/My-C%2B%2B-solutions-(recursion-with-cache-DP-recursion-with-cache-and-pruning)-with-explanation-(4ms)