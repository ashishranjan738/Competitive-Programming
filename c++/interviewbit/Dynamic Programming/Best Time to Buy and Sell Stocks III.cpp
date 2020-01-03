#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int Solution::maxProfit(const vector<int> &A);
};

// Say you have an array, A, for which the ith element is the price of a given stock on day i.

// Design an algorithm to find the maximum profit. You may complete at most 2 transactions.

// Return the maximum possible profit.

// Note: You may not engage in multiple transactions at the same time (ie, you must sell the stock before you buy again).

// Input Format:

// The first and the only argument is an integer array, A.
// Output Format:

// Return an integer, representing the maximum possible profit.
// Constraints:

// 1 <= length(A) <= 7e5
// 1 <= A[i] <= 1e7
// Examples:

// Input 1:
//     A = [1, 2, 1, 2]

// Output 1:
//     2

// Explanation 1:
//     Day 0 : Buy
//     Day 1 : Sell
//     Day 2 : Buy
//     Day 3 : Sell

// Input 2:
//     A = [7, 2, 4, 8, 7]

// Output 2:
//     6

// Explanation 2:
//     Day 1 : Buy
//     Day 3 : Sell

int Solution::maxProfit(const vector<int> &A)
{
    int buy1 = INT_MAX, sell1 = 0, buy2 = INT_MAX, sell2 = 0;
    for (int i : A)
    {
        buy1 = min(buy1, i);
        sell1 = max(sell1, i - buy1);
        buy2 = min(buy2, i - sell1);
        sell2 = max(sell2, i - buy2);
    }
    return sell2;
}

// Reference:
// https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iii/discuss/39611/Is-it-Best-Solution-with-O(n)-O(1)./242914
