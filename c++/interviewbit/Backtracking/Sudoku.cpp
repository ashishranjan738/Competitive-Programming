#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
void Solution::solveSudoku(vector<vector<char> > &A);
};
// Write a program to solve a Sudoku puzzle by filling the empty cells.
// Empty cells are indicated by the character '.'
// You may assume that there will be only one unique solution.

// http://upload.wikimedia.org/wikipedia/commons/thumb/f/ff/Sudoku-by-L2G-20050714.svg/250px-Sudoku-by-L2G-20050714.svg.png

// A sudoku puzzle,

// http://upload.wikimedia.org/wikipedia/commons/thumb/3/31/Sudoku-by-L2G-20050714_solution.svg/250px-Sudoku-by-L2G-20050714_solution.svg.png

// and its solution numbers marked in red.

// Example :

// For the above given diagrams, the corresponding input to your program will be

// [[53..7....], [6..195...], [.98....6.], [8...6...3], [4..8.3..1], [7...2...6], [.6....28.], [...419..5], [....8..79]]
// and we would expect your program to modify the above array of array of characters to

// [[534678912], [672195348], [198342567], [859761423], [426853791], [713924856], [961537284], [287419635], [345286179]]

bool check(vector<vector<char>> &grid,int i,int j,char c){
    for(int x=0;x<grid.size();x++){
        if(grid[i][x]==c || grid[x][j]==c)
            return false;
    }
    i=i-i%3;
    j=j-j%3;
    for(int dx=i;dx<i+3;dx++){
        for(int dy=j;dy<j+3;dy++){
            if(grid[dx][dy]==c)
                return false;
        }
    }
    return true;
}
bool solver(vector<vector<char>> &grid,int i,int j){
    if(i>=grid.size())
        return true;
    else if(j>=grid.size())
        return solver(grid,i+1,0);
    else if(grid[i][j]!='.')
        return solver(grid,i,j+1);
    for(char c='1';c!='9'+1;c++){
        if(check(grid,i,j,c)){
            grid[i][j]=c;
            if(solver(grid,i,j+1))
                return true;
        }
    }
    grid[i][j]='.';
    return false;
}
void Solution::solveSudoku(vector<vector<char> > &A) {
    solver(A,0,0);
}

// Reference:
// https://www.youtube.com/watch?v=JzONv5kaPJM