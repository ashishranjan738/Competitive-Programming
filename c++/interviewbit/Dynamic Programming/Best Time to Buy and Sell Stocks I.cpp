#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int Solution::maxProfit(const vector<int> &A);
};

// Say you have an array, A, for which the ith element is the price of a given stock on day i.

// If you were only permitted to complete at most one transaction (ie, buy one and sell one share of the stock), design an algorithm to find the maximum profit.

// Return the maximum possible profit.

// Input Format:

// The first and the only argument is an array of integers, A.
// Output Format:

// Return an integer, representing the maximum possible profit.
// Constraints:

// 1 <= len(A) <= 7e5
// 1 <= A[i] <= 1e7
// Examples:

// Input 1:
//     A = [1, 2]

// Output 1:
//     1

// Explanation:
//     Buy the stock on day 0, and sell it on day 1.

// Input 2:
//     A = [1, 4, 5, 2, 4]

// Output 2:
//     4

// Explanation:
//     Buy the stock on day 0, and sell it on day 2.

int Solution::maxProfit(const vector<int> &A)
{
    int buy = INT_MAX;
    int sell = 0;
    for (int i : A)
    {
        buy = min(buy, i);
        sell = max(sell, i - buy);
    }
    return sell;
}

// Reference:
// https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iii/discuss/39611/Is-it-Best-Solution-with-O(n)-O(1)./242914
