#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int Solution::solve(int A);
};

// Given a 3 x A board, find the number of ways to color it using at most 4 colors such that no 2 adjacent boxes have same color.

// Diagonal neighbors are not treated as adjacent boxes.

// Return the ways modulo 109 + 7 as the answer grows quickly.

// Input Format:

// The first and the only argument contains an integer, A.
// Output Format:

// Return an integer representing the number of ways to color the board.
// Constraints:

// 1 <= A < 100000
// Examples:

// Input 1:
//     A = 1

// Output 1:
//     36

// Input 2:
//     A = 2

// Output 2:
//     588

int Solution::solve(int A)
{
    int mod = 1000000007;
    long int color2 = 12, color3 = 24;
    for (int i = 2; i <= A; i++)
    {
        long int temp = color3;
        color3 = (11 * color3 + 10 * color2) % mod;
        color2 = (5 * temp + 7 * color2) % mod;
    }
    return (color2 + color3) % mod;
}

// Reference:
// https://www.geeksforgeeks.org/ways-color-3n-board-using-4-colors/