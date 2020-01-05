#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int Solution::arrange(string A, int B);
};

// You are given a sequence of black and white horses, and a set of K stables numbered 1 to K. You have to accommodate the horses into the stables in such a way that the following conditions are satisfied:

// You fill the horses into the stables preserving the relative order of horses. For instance, you cannot put horse 1 into stable 2 and horse 2 into stable 1. You have to preserve the ordering of the horses.
// No stable should be empty and no horse should be left unaccommodated.
// Take the product (number of white horses * number of black horses) for each stable and take the sum of all these products. This value should be the minimum among all possible accommodation arrangements
// Example:

// Input: {WWWB} , K = 2
// Output: 0

// Explanation:
// We have 3 choices {W, WWB}, {WW, WB}, {WWW, B}
// for first choice we will get 1*0 + 2*1 = 2.
// for second choice we will get 2*0 + 1*1 = 1.
// for third choice we will get 3*0 + 0*1 = 0.

// Of the 3 choices, the third choice is the best option.

// If a solution is not possible, then return -1

// Solution 1: Top Down approach (recursion + memoization)

// int solve(string s, int start, int k, vector<vector<int>> &m)
// {
//     if (start >= s.length() && k == 0)
//         return 0;
//     else if ((start >= s.length() && k >= 0) || k < 0)
//         return -1;
//     if (m[start][k] != INT_MAX)
//         return m[start][k];
//     int numOfWhite = 0, numOfBlack = 0, ans = INT_MAX;
//     for (int i = start; i < s.length(); i++)
//     {
//         (s[i] == 'W') ? numOfWhite++ : numOfBlack++;
//         ;
//         int next = solve(s, i + 1, k - 1, m);
//         if (next == -1)
//             continue;
//         ans = min(numOfWhite * numOfBlack + next, ans);
//     }
//     return m[start][k] = (ans == INT_MAX) ? -1 : ans;
// }
// int Solution::arrange(string A, int B)
// {
//     vector<vector<int>> m(A.length(), vector<int>(B + 1, INT_MAX));
//     return solve(A, 0, B, m);
// }

// Solution 2: Bottom Up Approach (tabular)

int Solution::arrange(string A, int B)
{
    int n = A.length();
    if (B > n)
        return -1;
    else if (B == n)
        return 0;
    vector<vector<int>> dp(B, vector<int>(n, 0));
    for (int i = 0; i < B; i++)
    {
        if (i == 0)
        {
            int wt = 0, bl = 0;
            for (int j = 0; j < n; j++)
            {
                A[j] == 'W' ? wt++ : bl++;
                dp[i][j] = wt * bl;
            }
        }
        else
        {
            for (int j = 0; j < n; j++)
            {
                int wt = 0, bl = 0;
                dp[i][j] = INT_MAX;
                for (int k = j; k >= 0; k--)
                {
                    A[k] == 'W' ? wt++ : bl++;
                    dp[i][j] = min(dp[i][j], bl * wt + ((k == 0) ? 0 : dp[i - 1][k - 1]));
                }
            }
        }
    }
    return dp[B - 1][n - 1];
}

// Reference:
// http://sahityapatel.blogspot.com/2017/08/interviewbit-dynamic-programming.html
// https://codevillage.wordpress.com/2016/09/06/mastering-dynamic-programming-2/