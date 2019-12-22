#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<vector<string> > Solution::solveNQueens(int n);
};

// The n-queens puzzle is the problem of placing n queens on an n×n chessboard such that no two queens attack each other.

// N Queens: Example 1

// Given an integer n, return all distinct solutions to the n-queens puzzle.

// Each solution contains a distinct board configuration of the n-queens’ placement, where 'Q' and '.' both indicate a queen and an empty space respectively.

// For example,
// There exist two distinct solutions to the 4-queens puzzle:

// [
//  [".Q..",  // Solution 1
//   "...Q",
//   "Q...",
//   "..Q."],

//  ["..Q.",  // Solution 2
//   "Q...",
//   "...Q",
//   ".Q.."]
// ]

void markVisited(vector<vector<int>> &visited,int i,int j,int n){
    visited[i][j]++;
    for(int x=1;x<n;x++){
        visited[i][x]++;
        visited[x][j]++;
        int dx=i+x;int dy=j+x;
        if(dx<n && dy<n && dx>=0 && dy>=0)
            visited[dx][dy]++;
        dx=i-x;dy=j-x;
        if(dx<n && dy<n && dx>=0 && dy>=0)
            visited[dx][dy]++;
        dx=i-x;dy=j+x;
        if(dx<n && dy<n && dx>=0 && dy>=0)
            visited[dx][dy]++;
        dx=i+x;dy=j-x;
        if(dx<n && dy<n && dx>=0 && dy>=0)
            visited[dx][dy]++;
    }
}
void unMarkVisited(vector<vector<int>> &visited,int i,int j,int n){
    visited[i][j]--;
    for(int x=1;x<n;x++){
        visited[i][x]--;
        visited[x][j]--;
        int dx=i+x;int dy=j+x;
        if(dx<n && dy<n && dx>=0 && dy>=0)
            visited[dx][dy]--;
        dx=i-x;dy=j-x;
        if(dx<n && dy<n && dx>=0 && dy>=0)
            visited[dx][dy]--;
        dx=i-x;dy=j+x;
        if(dx<n && dy<n && dx>=0 && dy>=0)
            visited[dx][dy]--;
        dx=i+x;dy=j-x;
        if(dx<n && dy<n && dx>=0 && dy>=0)
            visited[dx][dy]--;
    }
}
void solve(int n,int p,vector<vector<string>> &ans,vector<string> &current,vector<vector<int>> &visited){
    if(n==p){
        ans.push_back(current);
        return;
    }
    string s;
    for(int i=0;i<n;i++)
        s.push_back('.');
    for(int i=0;i<n;i++){
        if(visited[p][i]==0){
            s[i]='Q';
            markVisited(visited,p,i,n);
            current.push_back(s);
            solve(n,p+1,ans,current,visited);
            current.pop_back();
            unMarkVisited(visited,p,i,n);
            s[i]='.';
        }
    }
}


vector<vector<string> > Solution::solveNQueens(int n) {
    vector<vector<string>> ans;
    vector<vector<int>> visited(n,vector<int> (n,0));
    vector<string> tans;
    solve(n,0,ans,tans,visited);
    return ans;
}

// Reference:
// https://www.youtube.com/watch?v=xFv_Hl4B83A