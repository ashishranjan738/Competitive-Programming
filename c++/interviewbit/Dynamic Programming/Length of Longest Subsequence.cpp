#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int Solution::longestSubsequenceLength(const vector<int> &A);
};

// Given an array of integers, A of length N, find the length of longest subsequence which is first increasing then decreasing.

// Input Format:

// The first and the only argument contains an integer array, A.
// Output Format:

// Return an integer representing the answer as described in the problem statement.
// Constraints:

// 1 <= N <= 3000
// 1 <= A[i] <= 1e7
// Example:

// Input 1:
//     A = [1, 2, 1]

// Output 1:
//     3

// Explanation 1:
//     [1, 2, 1] is the longest subsequence.

// Input 2:
//     [1, 11, 2, 10, 4, 5, 2, 1]

// Output 2:
//     6

// Explanation 2:
//     [1 2 10 4 2 1] is the longest subsequence.

int Solution::longestSubsequenceLength(const vector<int> &A)
{
    if (A.size() < 2)
        return A.size();
    int iarr[A.size()], darr[A.size()];
    fill_n(iarr, A.size(), 1);
    fill_n(darr, A.size(), 1);
    for (int i = 1; i < A.size(); i++)
        for (int j = 0; j < i; j++)
            if (A[i] > A[j])
                iarr[i] = max(iarr[i], iarr[j] + 1);
                
    for (int i = A.size() - 2; i >= 0; i--)
        for (int j = A.size() - 1; j > i; j--)
            if (A[i] > A[j])
                darr[i] = max(darr[i], darr[j] + 1);

    int ans = iarr[0] + darr[0] - 1;
    // we don't need to do the brute force search over the combinations
    // as linear iterations covers all the combinations of LIS and LDS.
    for (int i = 1; i < A.size(); i++)
        ans = max(ans, iarr[i] + darr[i] - 1);
    return ans;
}
