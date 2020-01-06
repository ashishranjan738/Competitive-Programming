#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int Solution::chordCnt(int A);
};

// Given a number A, return number of ways you can draw A chords in a circle with 2 x A points such that no 2 chords intersect.

// Two ways are different if there exists a chord which is present in one way and not in other.

// Return the answer modulo 109 + 7.

// Input Format:

// The first and the only argument contains the integer A.
// Output Format:

// Return an integer answering the query as described in the problem statement.
// Constraints:

// 1 <= A <= 1000
// Examples:

// Input 1:
//     A = 1

// Output 1:
//     1

// Explanation 1:
//     If points are numbered 1 to 2 in clockwise direction, then different ways to draw chords are:
//     {(1-2)} only.
//     So, we return 1.

// Input 2:
//     A = 2

// Output 2:
//     2

// Explanation 2:
//     If points are numbered 1 to 4 in clockwise direction, then different ways to draw chords are:
//     {(1-2), (3-4)} and {(1-4), (2-3)}.
//     So, we return 2.

int Solution::chordCnt(int A)
{
    int totalNumberOfPoints = A * 2;
    const int mod = 1e9 + 7;
    long long int dp[totalNumberOfPoints + 1];
    memset(dp, 0, sizeof(dp));
    dp[2] = 1;
    // The idea is to divide the circle by picking up two points and calculate
    // number of chords in those two points
    for (int i = 4; i <= totalNumberOfPoints; i += 2)
    {
        for (int j = 0; j < i; j += 2)
        {
            int leftPoints = j, rightPoints = i - j - 2;
            if (leftPoints == 0)
                dp[i] = (dp[rightPoints] + dp[i]) % mod;
            else if (rightPoints == 0)
                dp[i] = (dp[leftPoints] + dp[i]) % mod;
            else
                dp[i] += (dp[leftPoints] * dp[rightPoints]) % mod;
        }
    }
    return dp[totalNumberOfPoints];
}

// Reference:
// https://www.includehelp.com/algorithms/non-intersecting-chords-using-dynamic-programming.aspx
