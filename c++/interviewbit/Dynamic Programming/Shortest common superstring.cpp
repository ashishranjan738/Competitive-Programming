#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int Solution::solve(vector<string> &A);
};

// Given a set of strings, A of length N.

// Return the length of smallest string which has all the strings in the set as substring.

// Input Format:

// The first and the only argument has an array of strings, A.
// Output Format:

// Return an integer representing the minimum possible length of the resulting string.
// Constraints:

// 1 <= N <= 18
// 1 <= A[i] <= 100
// Example:

// Input 1:
//     A = ["aaaa", "aa"]

// Output 1:
//     4

// Explanation 1:
//     Shortest string: "aaaa"

// Input 2:
//     A = ["abcd", "cdef", "fgh", "de"]

// Output 2:
//     8

// Explanation 2:
//     Shortest string: "abcdefgh"

// Note: use bitmasking for memoization
int calculateChainLength(vector<string> &words, int a, int b, vector<vector<int>> &cclDP)
{
    if ((a < 0 || a >= words.size()) && (b < 0 || b >= words.size()))
        return 0;
    else if ((a < 0 || a >= words.size()) && (b >= 0 && b < words.size()))
        return words[b].size();
    else if ((b < 0 || b >= words.size()) && (a >= 0 && a < words.size()))
        return words[a].size();
    else if (cclDP[a][b] != -1)
        return cclDP[a][b];

    int lengthDiff = words[b].length();
    for (int length = 1; length <= min(words[a].length(), words[b].length()); length++)
    {
        string s1 = words[a].substr(words[a].length() - length, length), s2 = words[b].substr(0, length);
        if (s1 != s2)
            continue;
        int t = words[b].length() - length;
        lengthDiff = min(lengthDiff, t);
    }
    return cclDP[a][b] = lengthDiff;
}
int findShotestChain(vector<string> &words, int lastTaken, int mask, int targetMask, vector<unordered_map<int, int>> &fscDP, vector<vector<int>> &cclDP)
{
    if (mask == targetMask)
        return 0;
    if (fscDP[lastTaken + 1].count(mask))
        return fscDP[lastTaken + 1][mask];
    int ans = INT_MAX;
    for (int i = 0; i < words.size(); i++)
    {
        if (!(mask & (1 << i)))
        {
            ans = min(ans, calculateChainLength(words, lastTaken, i, cclDP) + findShotestChain(words, i, mask | (1 << i), targetMask, fscDP, cclDP));
        }
    }

    return fscDP[lastTaken + 1][mask] = ans;
}

int Solution::solve(vector<string> &A)
{
    if (A.empty())
        return A.size();
    else if (A.size() == 1)
        return A[0].length();
    for (int i = 0; i < A.size(); i++)
    {
        for (int j = 0; j < A.size(); j++)
        {
            if (i != j && A[i].find(A[j]) != string::npos)
                A[j] = "";
        }
    }
    vector<string> newA;
    for (string s : A)
        if (s != "")
            newA.push_back(s);
    vector<vector<int>> cclDP(A.size(), vector<int>(A.size(), -1));
    vector<unordered_map<int, int>> fscDP(newA.size() + 1);
    return findShotestChain(newA, -1, 0, (1 << newA.size()) - 1, fscDP, cclDP);
}