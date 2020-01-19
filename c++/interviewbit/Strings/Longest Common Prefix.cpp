#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string Solution::longestCommonPrefix(vector<string> &A);
};

// Given the array of strings A,
// you need to find the longest string S which is the prefix of ALL the strings in the array.

// Longest common prefix for a pair of strings S1 and S2 is the longest string S which is the prefix of both S1
// and S2.

// For Example, longest common prefix of "abcdefgh" and "abcefgh" is "abc".

// Input Format

// The only argument given is an array of strings A.
// Output Format

// Return longest common prefix of all strings in A.
// For Example

// Input 1:
//     A = ["abcdefgh", "aefghijk", "abcefgh"]
// Output 1:
//     "a"
//     Explanation 1:
//         Longest common prefix of all the strings is "a".

// Input 2:
//     A = ["abab", "ab", "abcd"];
// Output 2:
//     "ab"
//     Explanation 2:
//         Longest common prefix of all the strings is "ab".

string getLongestCommonPrefix(string A, string B)
{
    int i = 0;
    string s;
    while (i < A.length() && i < B.length() && A[i] == B[i])
        s.push_back(A[i++]);
    return s;
}
string Solution::longestCommonPrefix(vector<string> &A)
{
    string prefix = A[0];
    for (int i = 1; i < A.size(); i++)
    {
        prefix = getLongestCommonPrefix(A[i], prefix);
    }
    return prefix;
}
