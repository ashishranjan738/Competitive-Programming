#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> Solution::solve(int A, vector<int> &B);
};

// It’s Tushar’s birthday today and he has N friends.

// Friends are numbered [0, 1, 2, …., N-1] and i-th friend have a positive strength B[i].

// Today being his birthday, his friends have planned to give him birthday bombs (kicks :P).

// Tushar’s friends know Tushar’s pain bearing limit and would hit accordingly.

// If Tushar’s resistance is denoted by A (>=0) then find the lexicographically smallest order of friends to kick Tushar so that the cumulative kick strength (sum of the strengths of friends who kicks) doesn’t exceed his resistance capacity and total no. of kicks hit are maximum.

// Also note that each friend can kick unlimited number of times (If a friend hits x times, his strength will be counted x times)

// Return the lexicographically smallest array of maximum length where the ith index represents the index of the friend who will hit.

// Note:

// 1. [a1, a2, ...., am] is lexicographically smaller than [b1, b2, .., bm]  if a1 < b1 or (a1 = b1 and a2 < b2) ... .
// 2. Input cases are such that the length of the answer does not exceed 100000.
// Input Format:

// The first argument contains an integer, A of length N.
// The second argument contains an array of integers, B.
// Output Format:

// Return an array of integer, as described in the problem statement.
// Constraints:

// 1 <= N <= 100
// 1 <= A <= 15000000
// 1 <= B[i] <= 3000
// Examples:

// Input 1:
//     A = 12
//     B = [3, 4]

// Output 1:
//     [0, 0, 0, 0]

// Explanation 1:
//     [1, 1, 1] is also a possible answer.

// Input 2:
//     A = 11
//     B = [6, 8, 5, 4, 7]

// Output 2:
//     [0, 2]

// Explanation 2:
//     [2, 3], [2, 2] and [3, 3] are also possible answers.

// Solution 1: Greedy approach
// vector<int> Solution::solve(int A, vector<int> &B)
// {
//     int minElement = B.front();
//     int minIndex = 0;

//     // Finding the minimum strength from B as minimum
//     // strength will give the maximum answer
//     for (int i = 0; i < B.size(); i++)
//     {
//         if (minElement > B[i])
//         {
//             minElement = B[i];
//             minIndex = i;
//         }
//     }

//     int maxKicks = A / minElement, currentSum = minElement * maxKicks;
//     vector<int> ans(maxKicks, minIndex);
//     int c = 0, i = 0;

//     // finding the candidate which can increase the sum
//     // but not decrease the maximumKicks
//     while (i < minIndex && c < maxKicks)
//     {
//         int temp = currentSum - B[ans[c]] + B[i];
//         if (temp > currentSum && temp <= A)
//         {
//             currentSum = temp;
//             ans[c++] = i;
//         }
//         else
//             i++;
//     }
//     return ans;
// }

// Solution 2: DP approach
vector<int> Solution::solve(int A, vector<int> &B)
{
    vector<int> dp(A + 1, -1), back(A + 1, 0), ans;
    for (int r = 0; r <= A; r++)
    {
        for (int i = 0; i < B.size(); i++)
        {
            if (B[i] <= r && dp[r] < dp[r - B[i]] + 1)
            {
                dp[r] = dp[r - B[i]] + 1;
                back[r] = i;
            }
        }
    }
    int r = A;
    while (r >= 0 && (r - B[back[r]]) >= 0)
    {
        r -= B[back[r]];
        ans.push_back(back[r]);
    }
    return ans;
}

// Reference:
// https://discuss.interviewbit.com/t/dp-solution-needed/23257/3
