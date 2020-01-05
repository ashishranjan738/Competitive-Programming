#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int Solution::minDistance(string A, string B);
};

// Given two strings A and B, find the minimum number of steps required to convert A to B. (each operation is counted as 1 step.)

// You have the following 3 operations permitted on a word:

// Insert a character
// Delete a character
// Replace a character

// Input Format:

// The first argument of input contains a string, A.
// The second argument of input contains a string, B.
// Output Format:

// Return an integer, representing the minimum number of steps required.
// Constraints:

// 1 <= length(A), length(B) <= 450
// Examples:

// Input 1:
//     A = "abad"
//     B = "abac"

// Output 1:
//     1

// Explanation 1:
//     Operation 1: Replace d with c.

// Input 2:
//     A = "Anshuman"
//     B = "Antihuman"

// Output 2:
//     2

// Explanation 2:
//     => Operation 1: Replace s with t.
//     => Operation 2: Insert i.

// Solution 1: Top Down approach (recursion + memoization)

// int solve(string A, string B, int i, int j, vector<vector<int>> &m)
// {
//     // when A's length is less than that of B's in that case
//     // we need to insert all B's remaining characters
//     if (i >= A.length())
//         return B.length() - j;
//     // when B's length is less than that of A's in that case
//     // we need to insert all A's remaining characters
//     else if (j >= B.length())
//         return A.length() - i;
//     // Logic for memoization
//     else if (m[i][j] != -1)
//         return m[i][j];
//     // if character at ith and jth positions are same then we don't
//     // need any change and can move forward
//     else if (A[i] == B[j])
//         return m[i][j] = solve(A, B, i + 1, j + 1, m);
//     // if the character at ith and jth positions are not same then
//     // we need to find the min of these following steps
//     // 1. Remove the current character from A: solve(A, B, i + 1, j, m)
//     // 2. Replace the current character from A: solve(A, B, i + 1, j + 1, m)
//     // 3. Insert a character in A: solve(A, B, i, j + 1, m)
//     else
//         return m[i][j] = 1 + min(solve(A, B, i + 1, j, m), min(solve(A, B, i + 1, j + 1, m), solve(A, B, i, j + 1, m)));
// }

// int Solution::minDistance(string A, string B)
// {
//     vector<vector<int>> m(A.length(), vector<int>(B.length(), -1));
//     return solve(A, B, 0, 0, m);
// }

// Solution 2: Bottom Up Approach (tabular)

int Solution::minDistance(string A, string B)
{
    vector<vector<int>> dp(A.length() + 1, vector<int>(B.length() + 1, 0));
    for (int i = 0; i <= A.length(); i++)
    {
        for (int j = 0; j <= B.length(); j++)
        {
            if (i == 0)
                dp[i][j] = j;
            else if (j == 0)
                dp[i][j] = i;
            else if (A[i - 1] == B[j - 1])
                dp[i][j] = dp[i - 1][j - 1];
            else
                dp[i][j] = 1 + min(dp[i - 1][j - 1], min(dp[i - 1][j], dp[i][j - 1]));
        }
    }
    return dp[A.length()][B.length()];
}

// Reference:
// https://www.geeksforgeeks.org/edit-distance-dp-5/
// https://www.youtube.com/watch?v=b6AGUjqIPsA&feature=youtu.be
