#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> Solution::maxset(vector<int> &A);
};

// Given an array of integers, A of length N, find out the maximum sum sub-array of non negative numbers from A.

// The sub-array should be contiguous i.e., a sub-array created by choosing the second and fourth element and skipping the third element is invalid.

// Maximum sub-array is defined in terms of the sum of the elements in the sub-array.

// Find and return the required subarray.

// NOTE:

//     1. If there is a tie, then compare with segment's length and return segment which has maximum length.
//     2. If there is still a tie, then return the segment with minimum starting index.

// Input Format:

// The first and the only argument of input contains an integer array A, of length N.
// Output Format:

// Return an array of integers, that is a subarray of A that satisfies the given conditions.
// Constraints:

// 1 <= N <= 1e5
// 1 <= A[i] <= 1e5
// Examples:

// Input 1:
//     A = [1, 2, 5, -7, 2, 3]

// Output 1:
//     [1, 2, 5]

// Explanation 1:
//     The two sub-arrays are [1, 2, 5] [2, 3].
//     The answer is [1, 2, 5] as its sum is larger than [2, 3].

// Input 2:
//     A = [10, -1, 2, 3, -4, 100]

// Output 2:
//     [100]

// Explanation 2:
//     The three sub-arrays are [10], [2, 3], [100].
//     The answer is [100] as its sum is larger than the other two.

// Hint:
// calculate sum of subarray of all positive numbers and reset the sum when a negative integer
// is found. Maintain the starting and ending index of the largest sum subarray.
vector<int> Solution::maxset(vector<int> &A)
{
    long long int i = 0, j = 0, sum = 0, ansSum = INT_MIN, ansi = 0, ansj = 0, ansLength = -1;
    while (j < A.size())
    {
        sum += A[j];
        if (A[j++] < 0)
        {
            i = j;
            sum = 0;
        }
        else if (sum > ansSum || (sum == ansSum && j - i > ansLength))
        {
            ansSum = sum;
            ansLength = j - i;
            ansj = j;
            ansi = i;
        }
    }
    vector<int> ans;
    for (int i = ansi; i < ansj; i++)
        ans.push_back(A[i]);
    return ans;
}
