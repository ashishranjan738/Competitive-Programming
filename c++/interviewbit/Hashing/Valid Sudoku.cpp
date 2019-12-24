#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int Solution::isValidSudoku(const vector<string> &A);
};

// Determine if a Sudoku is valid, according to: http://sudoku.com.au/TheRules.aspx

// The Sudoku board could be partially filled, where empty cells are filled with the character ‘.’.

// http://upload.wikimedia.org/wikipedia/commons/thumb/f/ff/Sudoku-by-L2G-20050714.svg/250px-Sudoku-by-L2G-20050714.svg.png

// The input corresponding to the above configuration :

// ["53..7....", "6..195...", ".98....6.", "8...6...3", "4..8.3..1", "7...2...6", ".6....28.", "...419..5", "....8..79"]
// A partially filled sudoku which is valid.

//  Note:
// A valid Sudoku board (partially filled) is not necessarily solvable. Only the filled cells need to be validated.
// Return 0 / 1 ( 0 for false, 1 for true ) for this problem

bool check(const vector<string> &A, int i, int j)
{
    char c = A[i][j];
    for (int x = 0; x < A.size(); x++)
    {
        if (c == A[i][x] && x != j)
            return false;
        if (c == A[x][j] && x != i)
            return false;
    }

    int di = i - i % 3;
    int dj = j - j % 3;
    for (int dx = di; dx < di + 3; dx++)
    {
        for (int dy = j; dy < dj + 3; dy++)
        {
            if (dx == i && dy == j)
                continue;
            if (c == A[dx][dy])
                return false;
        }
    }
    return true;
}

bool solve(const vector<string> &A, int i, int j)
{
    if (i >= A.size())
        return true;
    else if (j >= A.size())
        return solve(A, i + 1, 0);
    else if (A[i][j] == '.')
        return solve(A, i, j + 1);
    return check(A, i, j) && solve(A, i, j + 1);
}
int Solution::isValidSudoku(const vector<string> &A)
{
    return solve(A, 0, 0);
}
