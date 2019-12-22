#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<vector<int> > Solution::combinationSum(vector<int> &A, int B);
};

// Given a set of candidate numbers (C) and a target number (T), find all unique combinations in C where the candidate numbers sums to T.

// The same repeated number may be chosen from C unlimited number of times.

//  Note:
// All numbers (including target) will be positive integers.
// Elements in a combination (a1, a2, … , ak) must be in non-descending order. (ie, a1 ≤ a2 ≤ … ≤ ak).
// The combinations themselves must be sorted in ascending order.
// CombinationA > CombinationB iff (a1 > b1) OR (a1 = b1 AND a2 > b2) OR … (a1 = b1 AND a2 = b2 AND … ai = bi AND ai+1 > bi+1)
// The solution set must not contain duplicate combinations.
// Example,
// Given candidate set 2,3,6,7 and target 7,
// A solution set is:

// [2, 2, 3]
// [7]
//  Warning : DO NOT USE LIBRARY FUNCTION FOR GENERATING COMBINATIONS.
// Example : itertools.combinations in python.
// If you do, we will disqualify your submission retroactively and give you penalty points. 

void solve(vector<int> &candidates,int target,int sum,vector<int> &tans,vector<vector<int>> &ans){
    if(sum>target)
        return;
    else if(sum==target){
        ans.push_back(tans);
        return;
    }
    for(int a:candidates){
        if(tans.size()==0 || (tans.size() && a>=tans.back())){
            tans.push_back(a);
            solve(candidates,target,sum+a,tans,ans);
            tans.pop_back();
        }
    }
}
vector<vector<int> > Solution::combinationSum(vector<int> &A, int B) {
    vector<vector<int>> ans;
    vector<int> tans;
    set<int> s(A.begin(),A.end());
    A=vector<int> (s.begin(),s.end());
    solve(A,B,0,tans,ans);
    return ans;
}
