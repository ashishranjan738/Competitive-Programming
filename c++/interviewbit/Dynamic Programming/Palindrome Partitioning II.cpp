#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int Solution::minCut(string A);
};

// Given a string A, partition A such that every substring of the partition is a palindrome.

// Return the minimum cuts needed for a palindrome partitioning of A.

// Input Format:

// The first and the only argument contains the string A.
// Output Format:

// Return an integer, representing the answer as described in the problem statement.
// Constraints:

// 1 <= length(A) <= 501
// Examples:

// Input 1:
//     A = "aba"

// Output 1:
//     0

// Explanation 1:
//     "aba" is already a palindrome, so no cuts are needed.

// Input 2:
//     A = "aab"

// Output 2:
//     1

// Explanation 2:
//     Return 1 since the palindrome partitioning ["aa","b"] could be produced using 1 cut.


// Solution 1: Top Down approach (recursion + memoization)

// bool isPalindrome(string s)
// {
//     int i = 0, j = s.length() - 1;
//     while (i < j)
//         if (s[i++] != s[j--])
//             return false;
//     return true;
// }

// // getMinPalindromes returns the minimum number of palindromes
// // which can construct the string using concatenation
// int getMinPalindromes(string &s, int start, vector<int> &m)
// {
//     if (start >= s.length())
//         return 0;
//     if (m[start] != -1)
//         return m[start];
//     int ans = INT_MAX;
//     for (int length = s.length() - start; length > 0; length--)
//     {
//         if (isPalindrome(s.substr(start, length)))
//         {
//             int t = 1 + getMinPalindromes(s, start + length, m);
//             ans = min(t, ans);
//         }
//     }
//     return m[start] = (ans == INT_MAX) ? 0 : ans;
// }

// int Solution::minCut(string A)
// {
//     vector<int> m(A.size(), -1);
//     // minCut is (number of palindrome - 1) as cut will always
//     // be between two palindromes
//     return getMinPalindromes(A, 0, m) - 1;
// }

// Solution 2: Bottom Up Approach (tabular)

int Solution::minCut(string A)
{
    if(!A.length())
        return 0;
    vector<vector<bool>> palindrome(A.length(),vector<bool> (A.length(),0));
    vector<int> cuts(A.length(),0);
    for(int i=0;i<A.length();i++){
        int mi=i;
        for(int j=0;j<=i;j++){
            if(A[i]==A[j] && (i-j<2 || palindrome[j+1][i-1])){
                palindrome[j][i]=true;
                mi=(j==0)?0:min(mi,cuts[j-1]+1);
            }
        }
        cuts[i]=mi;
    }
    return cuts.back();
}

// Reference:
// https://leetcode.com/problems/palindrome-partitioning-ii/discuss/42213/Easiest-Java-DP-Solution-(97.36)
// https://www.youtube.com/watch?v=WPr1jDh3bUQ