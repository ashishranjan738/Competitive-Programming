#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<vector<int>> Solution::fourSum(vector<int> &A, int B);
};

// Given an array S of n integers, are there elements a, b, c, and d in S such that a + b + c + d = target? Find all unique quadruplets in the array which gives the sum of target.

//  Note:
// Elements in a quadruplet (a,b,c,d) must be in non-descending order. (ie, a ≤ b ≤ c ≤ d)
// The solution set must not contain duplicate quadruplets.
// Example :
// Given array S = {1 0 -1 0 -2 2}, and target = 0
// A solution set is:

//     (-2, -1, 1, 2)
//     (-2,  0, 0, 2)
//     (-1,  0, 0, 1)
// Also make sure that the solution set is lexicographically sorted.
// Solution[i] < Solution[j] iff Solution[i][0] < Solution[j][0] OR (Solution[i][0] == Solution[j][0] AND ... Solution[i][k] < Solution[j][k])

// Solution 1: We can create a pair with sum ans use the 2 sum approach for solving this

// vector<vector<int>> Solution::fourSum(vector<int> &A, int B)
// {
//     unordered_map<int, vector<pair<int, int>>> m;
//     sort(A.begin(), A.end());
//     for (int i = 0; i < A.size(); i++)
//     {
//         for (int j = i + 1; j < A.size(); j++)
//             m[A[i] + A[j]].push_back({i, j}); // creating pair with sum
//     }
//     vector<vector<int>> ans;
//     for (int i = 0; i < A.size(); i++)
//     {
//         if (i > 0 && A[i] == A[i - 1])
//             continue; // skipping duplicate elements
//         for (int j = i + 1; j < A.size(); j++)
//         {
//             if (j > i + 1 && A[j] == A[j - 1])
//                 continue; //skipping duplicate elements
//             int remaining = B - A[i] - A[j];
//             if (m.find(remaining) != m.end())
//             {
//                 for (pair<int, int> p : m[remaining])
//                 {
//                     if (p.first > j)
//                     { // This case involves taking those pairs whose index is greater than the selected pair from the loop
//                         vector<int> tans{A[i], A[j], A[p.first], A[p.second]};
//                         // avoinding duplicate elements by the below statement
//                         if (!ans.empty() && ans.back()[0] == tans[0] && ans.back()[1] == tans[1] && ans.back()[2] == tans[2] && ans.back()[3] == tans[3])
//                             continue;
//                         ans.push_back(tans);
//                     }
//                 }
//             }
//         }
//     }
//     return ans;
// }

// Solution 2: We can decompose any k sum problem into 2 sum and solve it via recursion
vector<vector<int>> ksum(int k, vector<int> &nums, int target, int start, int end)
{
    vector<vector<int>> ans;
    if (k == 1)
    {
        for (int i = start; i < end; i++)
            if (nums[i] == target)
                ans.push_back({nums[i]});
    }
    else if (k == 2)
    {
        int i = start;
        int j = end - 1;
        while (i < j)
        {
            int tsum = nums[i] + nums[j];
            if (tsum == target)
            {
                ans.push_back({nums[i++], nums[j--]});
                while (nums[i] == nums[i - 1])
                    i++;
                while (nums[j] == nums[j + 1])
                    j--;
            }
            else if (tsum > target)
                j--;
            else
                i++;
        }
    }
    else if (k > 2)
    {
        k--;
        for (int i = start; i < end - k; i++)
        {
            if (i > start && nums[i] == nums[i - 1])
                continue;
            if (k * nums[i + 1] > target - nums[i])
                break;
            vector<vector<int>> tans = ksum(k, nums, target - nums[i], i + 1, end);
            for (vector<int> v : tans)
            {
                if (v.size() == k)
                {
                    v.insert(v.begin(), nums[i]);
                    ans.push_back(v);
                }
            }
        }
    }
    return ans;
}

vector<vector<int>> Solution::fourSum(vector<int> &A, int B)
{
    sort(A.begin(), A.end());
    return ksum(4, A, B, 0, A.size());
}