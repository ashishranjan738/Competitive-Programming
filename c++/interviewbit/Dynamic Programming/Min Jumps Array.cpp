#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int Solution::jump(vector<int> &A);
};

// Given an array of non-negative integers, A, of length N, you are initially positioned at the first index of the array.

// Each element in the array represents your maximum jump length at that position.

// Return the minimum number of jumps required to reach the last index.

// If it is not possible to reach the last index, return -1.

// Input Format:

// The first and the only argument contains an integer array, A.
// Output Format:

// Return an integer, representing the answer as described in the problem statement.
// Constraints:

// 1 <= N <= 1e6
// 0 <= A[i] <= 50000
// Examples:

// Input 1:
//     A = [2, 1, 1]

// Output 1:
//     1

// Explanation 1:
//     The shortest way to reach index 2 is
//         Index 0 -> Index 2
//     that requires only 1 jump.

// Input 2:
//     A = [2,3,1,1,4]

// Output 2:
//     2

// Explanation 2:
//     The shortest way to reach index 4 is
//         Index 0 -> Index 1 -> Index 4
//     that requires 2 jumps.

int Solution::jump(vector<int> &A)
{
    if (A.size() <= 1) // This means we are already at destination
        return 0;
    if (!A.front()) // if the value of first is 0 we can't start jumping
        return -1;
    int ladder = A[0], jump = 1, stairs = A[0];
    for (int level = 1; level < A.size(); level++)
    {
        if (level == A.size() - 1)
            return jump;
        // ladder holds the max level we can reach to and if we update
        // it once we find a bigger ladder
        ladder = max(ladder, level + A[level]);
        stairs--;
        // stairs holds the number of stairs we have in the ladder.
        // if stairs becomes 0 them we should make a jump to a new ladder.
        if (!stairs)
        {
            // "ladder - level" becomes negative and zero then
            // we can't move forward.
            if (ladder - level <= 0)
                return -1;
            jump++;
            stairs = ladder - level;
        }
    }
    return -1;
}

// Reference:
// 1. https://www.geeksforgeeks.org/minimum-number-jumps-reach-endset-2on-solution/
// 2. https://www.youtube.com/watch?v=vBdo7wtwlXs