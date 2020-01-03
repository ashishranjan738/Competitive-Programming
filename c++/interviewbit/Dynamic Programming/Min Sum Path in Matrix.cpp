#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int Solution::minPathSum(vector<vector<int> > &A);
};

// Given a m x n grid filled with non-negative numbers, find a path from top left to bottom right which minimizes the sum of all numbers along its path.

//  Note: You can only move either down or right at any point in time. 
// Example :

// Input : 

//     [  1 3 2
//        4 3 1
//        5 6 1
//     ]

// Output : 8
//      1 -> 3 -> 2 -> 1 -> 1

// Solution 1: Recursive + memoization
// int solve(vector<vector<int>> &A,int i,int j,vector<vector<int>> &m){
//     if(i<0 || j<0 || i>=A.size() || j>=A.back().size())
//         return INT_MAX;
//     if(i==A.size()-1 && j==A.front().size()-1)
//         return A.back().back();
//     if(m[i][j]!=INT_MAX)
//         return m[i][j];
//     int ans=min(solve(A,i+1,j,m),solve(A,i,j+1,m));
//     return m[i][j]=(ans==INT_MAX)?INT_MAX:ans+A[i][j];
// }

// int Solution::minPathSum(vector<vector<int> > &A) {
//     vector<vector<int>> m(A.size(),vector<int> (A.back().size(),INT_MAX));
//     return solve(A,0,0,m);
// }

int Solution::minPathSum(vector<vector<int> > &A) {
    vector<vector<int>> grid(A.size(),vector<int> (A.back().size(),0));
    for(int i=0;i<A.size();i++){
        for(int j=0;j<A.back().size();j++){
            if(i==0 || j==0){
                if(i==0 && j==0)
                    grid[i][j]=A[i][j];
                else if(j>0 && !i)
                    grid[i][j]=grid[i][j-1]+A[i][j];
                else if(i>0 && !j)
                    grid[i][j]=grid[i-1][j]+A[i][j];
            } else {
                grid[i][j]=min(grid[i-1][j],grid[i][j-1])+A[i][j];
            }
        }
    }
    return grid.back().back();
}
