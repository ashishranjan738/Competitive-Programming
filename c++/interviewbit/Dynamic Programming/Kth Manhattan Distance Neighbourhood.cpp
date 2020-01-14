#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<vector<int>> Solution::solve(int K, vector<vector<int>> &grid);
};

// Given a matrix M of size nxm and an integer K, find the maximum element in the K manhattan distance neighbourhood for all elements in nxm matrix.
// In other words, for every element M[i][j] find the maximum element M[p][q] such that abs(i-p)+abs(j-q) <= K.

// Note: Expected time complexity is O(N*N*K)

// Constraints:

// 1 <= n <= 300
// 1 <= m <= 300
// 1 <= K <= 300
// 0 <= M[i][j] <= 1000
// Example:

// Input:
// M  = [[1,2,4],[4,5,8]] , K = 2

// Output:
// ans = [[5,8,8],[8,8,8]]

int max(int a, int b, int c, int d, int e)
{
    return max(a, max(max(b, c), max(d, e)));
}

vector<vector<int>> Solution::solve(int K, vector<vector<int>> &grid)
{
    int rows = grid.size(), columns = grid[0].size();
    vector<vector<int>> current = grid, nextDistance = grid;
    for (int k = 0; k < K; k++)
    {
        for (int r = 0; r < rows; r++)
        {
            for (int c = 0; c < columns; c++)
            {
                int curr = current[r][c];
                int up = (r == 0) ? -1 : current[r - 1][c];
                int down = (r == rows - 1) ? -1 : current[r + 1][c];
                int left = (c == 0) ? -1 : current[r][c - 1];
                int right = (c == columns - 1) ? -1 : current[r][c + 1];
                nextDistance[r][c] = max(curr, up, down, left, right);
            }
        }
        current = nextDistance;
    }
    return current;
}
