#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int Solution::maximumGap(const vector<int> &A);
};

// Given an array A of integers, find the maximum of j - i subjected to the constraint of A[i] <= A[j].

// If there is no solution possible, return -1.

// Example :

// A : [3 5 4 2]

// Output : 2
// for the pair (3, 4)

// Hint: 
// We need to find out the maxinmum differnce between j-i for which A[j]>=A[i]. So we can create two
// arrays holding the min elements from the left and the max elements from the right. Once we have
// constructed this array we can find the solution in a single traversal using two pointers.
int Solution::maximumGap(const vector<int> &A)
{
    vector<int> amin = A, amax = A;
    int n = A.size();
    for (int i = 1; i < n; i++)
    {
        amin[i] = min(amin[i - 1], amin[i]);
        amax[n - i - 1] = max(amax[n - i], amax[n - i - 1]);
    }
    int i = 0, j = 0, ans = -1;
    while (i < n and j < n)
    {
        if (amax[j] >= amin[i])
        {
            ans = max(ans, j - i);
            j++;
        }
        else
            i++;
    }
    return ans;
}

// Time Complexity: O(n);
// Space Complexity: O(n);

// Reference:
// https://www.geeksforgeeks.org/given-an-array-arr-find-the-maximum-j-i-such-that-arrj-arri/