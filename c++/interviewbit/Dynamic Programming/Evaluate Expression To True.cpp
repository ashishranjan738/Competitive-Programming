#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int Solution::cnttrue(string A);
};

// Given an expression, A, with operands and operators (OR , AND , XOR), in how many ways can you evaluate the expression to true, by grouping in different ways?

// Operands are only true and false.

// Return the number of ways to evaluate the expression modulo 103 + 3.

// Input Format:

// The first and the only argument of input will contain a string, A.

// The string A, may contain these characters:
//     '|' will represent or operator
//     '&' will represent and operator
//     '^' will represent xor operator
//     'T' will represent true operand
//     'F' will false
// Output:

// Return an integer, representing the number of ways to evaluate the string.
// Constraints:

// 1 <= length(A) <= 150
// Example:

// Input 1:
//     A = "T|F"

// Output 1:
//     1

// Explanation 1:
//     The only way to evaluate the expression is:
//         => (T|F) = T

// Input 2:
//     A = "T^T^F"

// Output 2:
//     0

// Explanation 2:
//     There is no way to evaluate A to a true statement.

int solve(string &s, int i, int j, bool solveForTrue, vector<vector<vector<int>>> &m)
{
    if (i > j)
        return 0;
    else if (i == j)
    {
        if (solveForTrue)
            return s[i] == 'T';
        else
            return s[i] == 'F';
    }
    else if (m[i][j][solveForTrue] != -1) // logic for memoization
        return m[i][j][solveForTrue];
    int ans = 0;
    for (int k = i + 1; k < j; k += 2)
    {
        // recursive calls for left and right counts
        int leftTrue = solve(s, i, k - 1, true, m), rightTrue = solve(s, k + 1, j, true, m);
        int leftFalse = solve(s, i, k - 1, false, m), rightFalse = solve(s, k + 1, j, false, m);
        // product of left and right counts
        int LTRT = (leftTrue * rightTrue) % 1003, LFRF = (leftFalse * rightFalse) % 1003;
        int LFRT = (leftFalse * rightTrue) % 1003, LTRF = (leftTrue * rightFalse) % 1003;
        if (s[k] == '|')
        {
            if (solveForTrue)
                ans += (LTRT + LTRF + LFRT) % 1003;
            else
                ans += LFRF;
        }
        else if (s[k] == '&')
        {
            if (solveForTrue)
                ans += LTRT;
            else
                ans += (LFRF + LTRF + LFRT) % 1003;
        }
        else if (s[k] == '^')
        {
            if (solveForTrue)
                ans += (LTRF + LFRT) % 1003;
            else
                ans += (LTRT + LFRF) % 1003;
        }
    }
    return m[i][j][solveForTrue] = ans % 1003;
}
int Solution::cnttrue(string A)
{
    vector<vector<vector<int>>> m(A.size(), vector<vector<int>>(A.size(), vector<int>(2, -1)));
    return solve(A, 0, A.length() - 1, true, m);
}

// Reference:
// https://www.youtube.com/watch?v=fOVkNROqrqc&list=PLQ9cQ3JqeqU_GzOU0aPVs4UBprzmFjnSI&index=1