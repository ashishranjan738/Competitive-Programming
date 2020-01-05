#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<vector<int>> Solution::avgset(vector<int> &A);
};

// Given an array with non negative numbers, divide the array into two parts such that the average of both the parts is equal.
// Return both parts (If exist).
// If there is no solution. return an empty list.

// Example:

// Input:
// [1 7 15 29 11 9]

// Output:
// [9 15] [1 7 11 29]

// The average of part is (15+9)/2 = 12,
// average of second part elements is (1 + 7 + 11 + 29) / 4 = 12

//  NOTE 1: If a solution exists, you should return a list of exactly 2 lists of integers A and B which follow the following condition :
// numElements in A <= numElements in B
// If numElements in A = numElements in B, then A is lexicographically smaller than B ( https://en.wikipedia.org/wiki/Lexicographical_order )
// NOTE 2: If multiple solutions exist, return the solution where length(A) is minimum. If there is still a tie, return the one where A is lexicographically smallest. NOTE 3: Array will contain only non negative numbers.

// getPartition returns a list of elements of the size provided that sums to the target.
// if no such partition exists it returns an empty list
vector<int> getPartition(vector<int> &nums, int start, int target, int size, vector<vector<map<int, vector<int>>>> &dp)
{
    if (start >= nums.size() || size < 1)
        return {};
    else if (nums[start] == target && size == 1)
        return {nums[start]};
    else if (dp[start][size].find(target) != dp[start][size].end())
        return dp[start][size][target];
    vector<int> ans;
    for (int i = start; i < nums.size(); i++)
    {
        if (nums[i] <= target)
        {
            vector<int> t = getPartition(nums, i + 1, target - nums[i], size - 1, dp);
            if (t.size() != 0)
            {
                ans.push_back(nums[i]);
                ans.insert(ans.end(), t.begin(), t.end());
                return dp[start][size][target] = ans;
            }
        }
    }
    return dp[start][size][target] = getPartition(nums, start + 1, target, size, dp);
}

vector<vector<int>> Solution::avgset(vector<int> &A)
{
    int totalSum = accumulate(A.begin(), A.end(), 0);
    bool isSolution = false;
    for (int i = 1; i <= A.size() - 1; i++)
    {
        if ((totalSum * i) % A.size() == 0)
        {
            isSolution = true;
            break;
        }
    }
    // because we need the answers in lexicographically sorted order
    sort(A.begin(), A.end());
    if (!isSolution)
        return {};
    vector<vector<map<int, vector<int>>>> dp(A.size(), vector<map<int, vector<int>>>(A.size()));
    for (int i = 1; i < A.size() - 1; i++)
    {
        // Because we need sum1 as a whole number
        if ((totalSum * i) % A.size() != 0)
            continue;
        int sum1 = (totalSum * i) / A.size();
        vector<int> res1 = getPartition(A, 0, sum1, i, dp), res2;
        if (res1.empty())
            continue;
        int ptr1 = 0, ptr2 = 0;
        // adding leftover elements to second partition
        while (ptr1 < A.size() || ptr2 < res1.size())
        {
            if (ptr2 < res1.size() && A[ptr1] == res1[ptr2])
            {
                ptr1++;
                ptr2++;
                continue;
            }
            res2.push_back(A[ptr1++]);
        }
        return {res1, res2};
    }
    return {};
}

// Reference:
// https://www.youtube.com/watch?v=FBQbm26tSzA
// https://www.geeksforgeeks.org/subset-sum-problem-dp-25/
