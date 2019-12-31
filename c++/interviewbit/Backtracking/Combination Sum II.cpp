#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<vector<int>> Solution::combinationSum(vector<int> &A, int B);
};

// Given a collection of candidate numbers (C) and a target number (T), find all unique combinations in C where the candidate numbers sums to T.

// Each number in C may only be used once in the combination.

//  Note:
// All numbers (including target) will be positive integers.
// Elements in a combination (a1, a2, … , ak) must be in non-descending order. (ie, a1 ≤ a2 ≤ … ≤ ak).
// The solution set must not contain duplicate combinations.
// Example :

// Given candidate set 10,1,2,7,6,1,5 and target 8,

// A solution set is:

// [1, 7]
// [1, 2, 5]
// [2, 6]
// [1, 1, 6]
//  Warning : DO NOT USE LIBRARY FUNCTION FOR GENERATING COMBINATIONS.
// Example : itertools.combinations in python.
// If you do, we will disqualify your submission retroactively and give you penalty points.

void solve(vector<int> &candidates, int target, int previous, int sum, vector<int> &tans, vector<vector<int>> &ans)
{
    if (sum > target)
        return;
    else if (sum == target)
    {
        ans.push_back(tans);
        return;
    }
    for (int i = previous; i < candidates.size(); i++)
    {
        int a = candidates[i];
        // avoiding duplicates by iterating same candidates twice
        if (i && a == candidates[i - 1] && i > previous)
            continue;
        tans.push_back(a);
        solve(candidates, target, i + 1, sum + a, tans, ans);
        tans.pop_back();
    }
}

vector<vector<int>> Solution::combinationSum(vector<int> &A, int B)
{
    vector<vector<int>> ans;
    vector<int> tans;
    sort(A.begin(), A.end());
    solve(A, B, 0, 0, tans, ans);
    return ans;
}
