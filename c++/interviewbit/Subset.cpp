#include <bits/stdc++.h>
using namespace std;

class Solution {
    public:
    vector<vector<int>> subsets(vector<int> &);
};
// Given a set of distinct integers, S, return all possible subsets.

//  Note:
// Elements in a subset must be in non-descending order.
// The solution set must not contain duplicate subsets.
// Also, the subsets should be sorted in ascending ( lexicographic ) order.
// The list is not necessarily sorted.
// Example :

// If S = [1,2,3], a solution is:

// [
//   [],
//   [1],
//   [1, 2],
//   [1, 2, 3],
//   [1, 3],
//   [2],
//   [2, 3],
//   [3],
// ]

void solve(vector<vector<int>> &ans, vector<int> &A, vector<int> prev, int pos)
{
    if (pos >= A.size())
    {
        return;
    }

    vector<int> tprev(prev.begin(), prev.end());
    prev.push_back(A[pos]);
    ans.push_back(prev);
    solve(ans, A, prev, pos + 1);
    solve(ans, A, tprev, pos + 1);
}
vector<vector<int>> Solution::subsets(vector<int> &A)
{
    vector<vector<int>> ans;
    ans.push_back(vector<int>());
    sort(A.begin(), A.end());
    solve(ans, A, vector<int>(), 0);
    return ans;
}
