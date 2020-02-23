#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<vector<int>> Solution::generateMatrix(int A);
};

// Given an integer A, generate a square matrix filled with elements from 1 to A2 in spiral order.

// Input Format:

// The first and the only argument contains an integer, A.
// Output Format:

// Return a 2-d matrix of size A x A satisfying the spiral order.
// Constraints:

// 1 <= A <= 1000
// Examples:

// Input 1:
//     A = 3

// Output 1:
//     [   [ 1, 2, 3 ],
//         [ 8, 9, 4 ],
//         [ 7, 6, 5 ]   ]

// Input 2:
//     4

// Output 2:
//     [   [1, 2, 3, 4],
//         [12, 13, 14, 5],
//         [11, 16, 15, 6],
//         [10, 9, 8, 7]   ]

vector<vector<int>> Solution::generateMatrix(int A)
{
    int n = A;
    int dir = 0, i = 0, j = 0, k = n - 1, l = n - 1;
    int sum = 1;
    vector<vector<int>> mat(n, vector<int>(n, 0));
    while (i <= l && j <= k)
    {
        if (dir == 0)
        {
            for (int it = j; it <= k; it++)
                mat[i][it] = sum++;
            i++;
        }
        else if (dir == 1)
        {
            for (int it = i; it <= l; it++)
                mat[it][k] = sum++;
            k--;
        }
        else if (dir == 2)
        {
            for (int it = k; it >= j; it--)
                mat[l][it] = sum++;
            l--;
        }
        else if (dir == 3)
        {
            for (int it = l; it >= i; it--)
                mat[it][j] = sum++;
            j++;
        }
        dir++;
        dir = dir % 4;
    }
    return mat;
}
