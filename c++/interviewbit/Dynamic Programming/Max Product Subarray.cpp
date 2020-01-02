#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int Solution::maxProduct(const vector<int> &A);
};

// Find the contiguous subarray within an array (containing at least one number) which has the largest product.
// Return an integer corresponding to the maximum product possible.

// Example :

// Input : [2, 3, -2, 4]
// Return : 6

// Possible with [2, 3]

int Solution::maxProduct(const vector<int> &A)
{
    if (A.empty())
        return A.size();
    int ans = A.front();
    for (int curr_min = ans, curr_max = ans, i = 1; i < A.size(); i++)
    {
        if (A[i] < 0)
            swap(curr_min, curr_max);
        curr_min = min(A[i], curr_min * A[i]);
        curr_max = max(A[i], curr_max * A[i]);
        ans = max(ans, curr_max);
    }
    return ans;
}
