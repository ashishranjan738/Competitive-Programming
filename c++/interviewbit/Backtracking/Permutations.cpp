#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<vector<int>> Solution::permute(vector<int> &A);
};

// Given a collection of numbers, return all possible permutations.

// Example:

// [1,2,3] will have the following permutations:

// [1,2,3]
// [1,3,2]
// [2,1,3]
// [2,3,1]
// [3,1,2]
// [3,2,1]
//  NOTE
// No two entries in the permutation sequence should be the same.
// For the purpose of this problem, assume that all the numbers in the collection are unique.

void solve(vector<vector<int>> &ans, vector<int> &tans, vector<int> &A, bool visited[])
{
    if (tans.size() == A.size())
        ans.push_back(tans);
    for (int i = 0; i < A.size(); i++)
    {
        if (!visited[i])
        {
            visited[i] = 1;
            tans.push_back(A[i]);
            solve(ans, tans, A, visited);
            tans.pop_back();
            visited[i] = 0;
        }
    }
}
vector<vector<int>> Solution::permute(vector<int> &A)
{
    vector<vector<int>> ans;
    vector<int> tans;
    bool visited[A.size()];
    fill_n(visited, A.size(), false);
    solve(ans, tans, A, visited);
    return ans;
}
