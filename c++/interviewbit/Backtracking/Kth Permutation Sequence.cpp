#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string Solution::getPermutation(int A, int B);
};

// The set [1,2,3,…,n] contains a total of n! unique permutations.

// By listing and labeling all of the permutations in order,
// We get the following sequence (ie, for n = 3 ) :

// 1. "123"
// 2. "132"
// 3. "213"
// 4. "231"
// 5. "312"
// 6. "321"
// Given n and k, return the kth permutation sequence.

// For example, given n = 3, k = 4, ans = "231"

//  Good questions to ask the interviewer :
//  1. What if n is greater than 10. How should multiple digit numbers be represented in string?
//  In this case, just concatenate the number to the answer.
// so if n = 11, k = 1, ans = "1234567891011"
//  2. Whats the maximum value of n and k?
//  In this case, k will be a positive integer thats less than INT_MAX.
// n is reasonable enough to make sure the answer does not bloat up a lot.

string solve(int k, vector<int> &nums, int factorial[])
{
    int n = nums.size();
    if (n == 0 || k > factorial[n])
        return "";
    int f = factorial[n - 1];
    int pos = k / f;
    k %= f;
    string ch = to_string(nums[pos]);
    nums.erase(nums.begin() + pos);
    return ch + solve(k, nums, factorial);
}

string Solution::getPermutation(int A, int B)
{
    int factorial[A + 1];
    int sum = 1;
    factorial[0] = 1;
    for (int i = 1; i <= A; i++)
    {
        if (i > 12)
        {
            factorial[i] = INT_MAX;
        }
        else
        {
            sum *= i;
            factorial[i] = sum;
        }
    }
    vector<int> nums;
    for (int i = 1; i <= A; i++)
    {
        nums.emplace_back(i);
    }
    return solve(B - 1, nums, factorial);
}

// Refernce:
// https://leetcode.com/problems/permutation-sequence/discuss/22507/%22Explain-like-I'm-five%22-Java-Solution-in-O(n)
