#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int Solution::canJump(vector<int> &A);
};

// Given an array of non-negative integers, A, you are initially positioned at the first index of the array.

// Each element in the array represents your maximum jump length at that position.

// Determine if you are able to reach the last index.

// Input Format:

// The first and the only argument of input will be an integer array A.
// Output Format:

// Return an integer, representing the answer as described in the problem statement.
//     => 0 : If you cannot reach the last index.
//     => 1 : If you can reach the last index.
// Constraints:
// 1 <= len(A) <= 1e6
// 0 <= A[i] <= 30

// Examples:

// Input 1:
//     A = [2,3,1,1,4]

// Output 1:
//     1

// Explanation 1:
//     Index 0 -> Index 2 -> Index 3 -> Index 4 -> Index 5

// Input 2:
//     A = [3,2,1,0,4]

// Output 2:
//     0

// Explanation 2:
//     There is no possible path to reach the last index.

int Solution::canJump(vector<int> &A)
{
    if (A.size() <= 1)
        return true;
    if (!A.front())
        return false;
    int ladder = A[0], stairs = A[0];
    for (int level = 1; level < A.size(); level++)
    {
        if (level == A.size() - 1)
            return true;
        // ladder holds the max level we can reach to and if we update
        // it once we find a bigger ladder
        ladder = max(ladder, A[level] + level);
        stairs--;
        // stairs holds the number of stairs we have in the ladder.
        // if stairs becomes 0 them we should make a jump to a new ladder.
        if (!stairs)
        {
            if (ladder - level <= 0)
                return false;
            stairs = ladder - level;
        }
    }
    return false;
}

// Reference:
// 1. https://www.geeksforgeeks.org/minimum-number-jumps-reach-endset-2on-solution/
// 2. https://www.youtube.com/watch?v=vBdo7wtwlXs