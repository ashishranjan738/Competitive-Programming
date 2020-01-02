#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int Solution::solve(vector<vector<int>> &A);
};

// Given a binary grid i.e. a 2D grid only consisting of 0’s and 1’s, find the area of the largest rectangle inside the grid such that all the cells inside the chosen rectangle should have 1 in them. You are allowed to permutate the columns matrix i.e. you can arrange each of the column in any order in the final grid. Please follow the below example for more clarity.

// Lets say we are given a binary grid of 3 * 3 size.

// 1 0 1

// 0 1 0

// 1 0 0

// At present we can see that max rectangle satisfying the criteria mentioned in the problem is of 1 * 1 = 1 area i.e either of the 4 cells which contain 1 in it. Now since we are allowed to permutate the columns of the given matrix, we can take column 1 and column 3 and make them neighbours. One of the possible configuration of the grid can be:

// 1 1 0

// 0 0 1

// 1 0 0

// Now In this grid, first column is column 1, second column is column 3 and third column is column 2 from the original given grid. Now, we can see that if we calculate the max area rectangle, we get max area as 1 * 2 = 2 which is bigger than the earlier case. Hence 2 will be the answer in this case.

// Hint: The idea is to store the count of consecutive 1s
// of columns in an other 2d matrix of same size and the
// maximum area of rectangles from that matrix.
int Solution::solve(vector<vector<int>> &A)
{
    if (A.empty())
        return A.size();
    int nR = A.size(), nC = A.front().size();
    int arr[nR][nC];
    memset(&arr, 0, sizeof(arr));
    for (int i = 0; i < nC; i++)
    {
        arr[0][i] = A[0][i];
        for (int j = 1; j < nR; j++)
        {
            if (!A[j][i])
                arr[j][i] = 0;
            else
                arr[j][i] = arr[j - 1][i] + 1;
        }
    }
    for (int i = 0; i < nR; i++)
        sort(arr[i], arr[i] + nC, greater<int>());
    int ans = 0;
    for (int i = 0; i < nR; i++)
        for (int j = 0; j < nC; j++)
            ans = max(ans, (j + 1) * arr[i][j]);
    return ans;
}

// Reference:
// https://www.geeksforgeeks.org/find-the-largest-rectangle-of-1s-with-swapping-of-columns-allowed/