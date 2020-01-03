#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int Solution::numDecodings(string A);
};

// A message containing letters from A-Z is being encoded to numbers using the following mapping:

// 'A' -> 1
// 'B' -> 2
// ...
// 'Z' -> 26
// Given an encoded message containing digits, determine the total number of ways to decode it.

// Input Format:

// The first and the only argument is a string A.
// Output Format:

// Return an integer, representing the number of ways to decode the string.
// Constraints:

// 1 <= length(A) <= 1e5
// Example :

// Input 1:
//     A = "8"

// Output 1:
//     1

// Explanation 1:
//     Given encoded message "8", it could be decoded as only "H" (8).

//     The number of ways decoding "8" is 1.

// Input 2:
//     A = "12"

// Output 2:
//     2

// Explanation 2:
//     Given encoded message "12", it could be decoded as "AB" (1, 2) or "L" (12).

//     The number of ways decoding "12" is 2.

int solve(string &A, int i, vector<int> &m)
{
    if (i >= A.length())
        return 1;
    int ans = 0;
    // if the solution already exist then reuse it
    if (m[i] != -1)
        return m[i];
    // case 1: when taking a single digit then single
    // digit must lie within 0 and 10.
    if (A[i] > '0' && A[i] <= '9')
        ans += solve(A, i + 1, m);
    // case 2: when taking a 2 digit to decode then
    // 2 digit must not have '0' as prefix and must lie
    // within 0 and 27.
    if (i + 1 < A.length() && A[i] != '0' && stoi(A.substr(i, 2)) > 0 && stoi(A.substr(i, 2)) < 27)
        ans += solve(A, i + 2, m);
    return m[i] = ans;
}

int Solution::numDecodings(string A)
{
    vector<int> m(A.size(), -1);
    return solve(A, 0, m);
}
