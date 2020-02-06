#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int Solution::numDistinct(string a, string b);
};

// Given two sequences A, B, count number of unique ways in sequence A, to form a subsequence that is identical to the sequence B.

// Subsequence : A subsequence of a string is a new string which is formed from the original string by deleting some (can be none) of the characters without disturbing the relative positions of the remaining characters. (ie, “ACE” is a subsequence of “ABCDE” while “AEC” is not).

// Input Format:

// The first argument of input contains a string, A.
// The second argument of input contains a string, B.
// Output Format:

// Return an integer representing the answer as described in the problem statement.
// Constraints:

// 1 <= length(A), length(B) <= 700
// Example :

// Input 1:
//     A = "abc"
//     B = "abc"

// Output 1:
//     1

// Explanation 1:
//     Both the strings are equal.

// Input 2:
//     A = "rabbbit"
//     B = "rabbit"

// Output 2:
//     3

// Explanation 2:
//     These are the possible removals of characters:
//         => A = "ra_bbit"
//         => A = "rab_bit"
//         => A = "rabb_it"

//     Note: "_" marks the removed character.

// Solution 1: Top Down approach (recursion + memoization)
// int solve(string &a,string &b,int i,int j, vector<vector<int>> &dp){
//     if(i>=a.length()&&j>=b.length())
//         return 1;
//     if(i>=a.length() && j<b.length())
//         return 0;
//     else if(j>=b.length()&&i<a.length())
//         return solve(a,b,i+1,j,dp);
//     if(dp[i][j]!=-1)
//         return dp[i][j];
//     int ans=0;
//     if(a[i]==b[j])
//         ans+=solve(a,b,i+1,j+1,dp);
//     ans+=solve(a,b,i+1,j,dp);
//     return dp[i][j]=ans;
// }

// int Solution::numDistinct(string a, string b) {
//     if(b.length()>a.length()||(a.length()==b.length()&&a!=b))
//         return 0;
//     if(a==b)
//         return 1;
//     vector<vector<int>> dp(a.length()+1,vector<int> (b.length()+1,-1));
//     return solve(a,b,0,0,dp);
// }

// Solution 2: Bottom Up Approach (tabular)
int Solution::numDistinct(string a, string b)
{
    if (b.length() > a.length() || (a.length() == b.length() && a != b))
        return 0;
    if (a == b)
        return 1;
    vector<vector<int>> dp(a.length() + 1, vector<int>(b.length() + 1, 0));
    for (int i = 0; i <= a.length(); i++)
        dp[i][0] = 1;
    for (int i = 1; i <= a.length(); i++)
    {
        for (int j = 1; j <= b.length(); j++)
        {
            if (a[i - 1] == b[j - 1])
                dp[i][j] += dp[i - 1][j - 1];
            dp[i][j] += dp[i - 1][j];
        }
    }
    return dp[a.length()][b.length()];
}
