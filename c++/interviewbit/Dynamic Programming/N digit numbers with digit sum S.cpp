#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int Solution::solve(int A, int B);
};

// Find out the number of N digit numbers, whose digits on being added equals to a given number S. Note that a valid number starts from digits 1-9 except the number 0 itself. i.e. leading zeroes are not allowed.

// Since the answer can be large, output answer modulo 1000000007

// **

// N = 2, S = 4
// Valid numbers are {22, 31, 13, 40}
// Hence output 4.

// Solution 1: Top Down approach (recursion + memoization)
int sol(int targetSum, int currentSum, int currentDigits, int targetDigits, vector<unordered_map<int, int>> &m)
{
    if (currentSum == targetSum && currentDigits == targetDigits)
        return 1;
    if (currentDigits > targetDigits || currentSum > targetSum)
        return 0;
    if (m[currentDigits].count(currentSum))
        return m[currentDigits][currentSum];
    long long int ans = 0;
    for (int i = (currentDigits == 0) ? 1 : 0; i <= 9; i++)
    {
        ans += sol(targetSum, currentSum + i, currentDigits + 1, targetDigits, m);
        ans %= 1000000007;
    }
    return m[currentDigits][currentSum] = ans;
}

int Solution::solve(int A, int B)
{
    vector<unordered_map<int, int>> m(A + 1);
    return sol(B, 0, 0, A, m);
}

// TODO: Implement bottom up (tabular method)