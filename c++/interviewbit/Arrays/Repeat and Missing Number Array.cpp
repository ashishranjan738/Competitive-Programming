#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> Solution::repeatedNumber(const vector<int> &A);
};

// Please Note:
// There are certain problems which are asked in the interview to also check how you take care of overflows in your problem.
// This is one of those problems.
// Please take extra care to make sure that you are type-casting your ints to long properly and at all places. Try to verify if your solution works if number of elements is as large as 105

//  Food for thought :
// Even though it might not be required in this problem, in some cases, you might be required to order the operations cleverly so that the numbers do not overflow.
// For example, if you need to calculate n! / k! where n! is factorial(n), one approach is to calculate factorial(n), factorial(k) and then divide them.
// Another approach is to only multiple numbers from k + 1 ... n to calculate the result.
// Obviously approach 1 is more susceptible to overflows.
// You are given a read only array of n integers from 1 to n.

// Each integer appears exactly once except A which appears twice and B which is missing.

// Return A and B.

// Note: Your algorithm should have a linear runtime complexity. Could you implement it without using extra memory?

// Note that in your output A should precede B.

// Example:

// Input:[3 1 2 5 3]

// Output:[3, 4]

// A = 3, B = 4


/*
Hint:
The idea is to find the xor of all the elements in the array and also xor 1...n.
This will give us xor of missing number and the repeating number as all other elements
will nullify each other. Now once we have the xor we can find the right most set bit
from the xored value because we want to seperate the repeating number and the missing
number and the rightMost set bit in the xored value will either be comming from the
missing number or the repeating number.
So xoring all the elements with rightMost found bit is set in the arr and xoring all
the numerbers from 1..n which has has rightMost bit found is set will either give us 
the repeating number or the missing number. Now we can add one more check to confirm
which is the repeating number by checking the array once again.
*/
vector<int> Solution::repeatedNumber(const vector<int> &A)
{
    int xorValue = 0, n = A.size();
    // xoring all elements in the array and 1..n.
    for (int i = 0; i < n; i++)
        xorValue ^= A[i] ^ (i + 1);
    // finding the rightMost set bit
    int rightMostSetBit = xorValue & ~(xorValue - 1);
    // finding the repeating number and missingNumber
    int repeatingNumber = 0, missingNumber = 0;
    for (int i = 0; i < n; i++)
    {
        if (rightMostSetBit & A[i])
            repeatingNumber ^= A[i];
        else
            missingNumber ^= A[i];
        if ((i + 1) & rightMostSetBit)
            repeatingNumber ^= (i + 1);
        else
            missingNumber ^= (i + 1);
    }
    // confirming the repeating number is correct
    if (find(A.begin(), A.end(), repeatingNumber) == A.end())
        swap(repeatingNumber, missingNumber);
    return {repeatingNumber, missingNumber};
}

// Reference:
// https://www.geeksforgeeks.org/find-a-repeating-and-a-missing-number/
// https://www.youtube.com/watch?v=gWhSiGETn9Y