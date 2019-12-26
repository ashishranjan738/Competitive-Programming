#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string Solution::minWindow(string A, string B);
};

// Given a string S and a string T, find the minimum window in S which will contain all the characters in T in linear time complexity.
// Note that when the count of a character C in T is N, then the count of C in minimum window in S should be at least N.

// Example :

// S = "ADOBECODEBANC"
// T = "ABC"
// Minimum window is "BANC"

//  Note:
// If there is no such window in S that covers all characters in T, return the empty string ''.
// If there are multiple such windows, return the first occurring minimum window ( with minimum start index ).

string Solution::minWindow(string A, string B)
{
    if (B.length() > A.length())
        return "";
    int bank[256]; // bank holds the frequency of characters of string B
    fill_n(bank, 256, 0);
    for (char c : B)
        bank[c]++;
    int left, right, count;
    string ans;
    int ansLength = A.length() + 1;
    left = right = count = 0; 
    // count holds the number of characters of string B 
    // present in the answer substring

    // using sliding window to find the minimum substring
    while (right < A.length())
    {
        if (bank[A[right++]]-- > 0)
        {
            count++;
        }
        while (count == B.length())
        {
            int substrLength = right - left;
            if (ansLength > substrLength)
            {
                ansLength = substrLength;
                ans = A.substr(left, substrLength);
            }
            if (++bank[A[left++]] > 0)
            {
                count--;
            }
        }
    }
    return ans;
}

// Reference:
// https://www.youtube.com/watch?v=9odu9ImG9oY&t=694s
// https://leetcode.com/problems/minimum-window-substring/discuss/26917/16ms-simple-and-neat-c%2B%2B-solution-only-using-a-vector.-Detailed-explanation