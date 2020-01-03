#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string Solution::longestPalindrome(string A);
};

// Given a string S, find the longest palindromic substring in S.

// Substring of string S:

// S[i...j] where 0 <= i <= j < len(S)

// Palindrome string:

// A string which reads the same backwards. More formally, S is palindrome if reverse(S) = S.

// Incase of conflict, return the substring which occurs first ( with the least starting index ).

// Example :

// Input : "aaaabaaa"
// Output : "aaabaaa"

string Solution::longestPalindrome(string A)
{
    if (A.length() <= 1)
        return A;

    int n = A.length();
    // Note: using 2d boolean matrix was giving segmentaton fault
    // for large test cases in interviewbit
    vector<vector<bool>> dp(n, vector<bool>(n, 0));
    for (int i = 0; i < A.length(); i++)
        dp[i][i] = true;
    int maxLength = 1;
    int startIndex = 0;

    for (int i = n - 1; i >= 0; i--)
    {
        for (int dist = 1; dist < n - i; dist++)
        {
            int j = i + dist;
            dp[i][j] = (dist == 1) ? A[i] == A[j] : A[i] == A[j] && dp[i + 1][j - 1];
            if (dp[i][j])
            {
                int tlength = j - i + 1;
                if (maxLength <= tlength)
                {
                    startIndex = i;
                    maxLength = tlength;
                }
            }
        }
    }
    return A.substr(startIndex, maxLength);
}

// Reference:
// https://leetcode.com/problems/longest-palindromic-substring/discuss/151144/Bottom-up-DP-Logical-Thinking