#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int Solution::diffPossible(const vector<int> &A, int B);
};

// Given an array A of integers and another non negative integer k, find if there exists 2 indices i and j such that A[i] - A[j] = k, i != j.

// Example :

// Input :

// A : [1 5 3]
// k : 2
// Output :

// 1
// as 3 - 1 = 2

// Return 0 / 1 for this problem.

int Solution::diffPossible(const vector<int> &A, int B)
{
    unordered_map<int, int> m;
    for (int i = 0; i < A.size(); i++)
    {
        int sum = A[i] + B;
        int diff = A[i] - B;
        if (m.find(sum) != m.end() && m[sum] != i)
            return true;
        if (m.find(diff) != m.end() && m[diff] != i)
            return true;
        m[A[i]] = i;
    }
    return false;
}
