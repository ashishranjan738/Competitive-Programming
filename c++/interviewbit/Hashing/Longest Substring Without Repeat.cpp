#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int Solution::lengthOfLongestSubstring(string A);
};

// Given a string,
// find the length of the longest substring without repeating characters.

// Example:

// The longest substring without repeating letters for "abcabcbb" is "abc", which the length is 3.

// For "bbbbb" the longest substring is "b", with the length of 1.

int Solution::lengthOfLongestSubstring(string A)
{
    int ans = 0;
    unordered_map<char, int> m;
    int start = -1;
    for (int i = 0; i < A.length(); i++)
    {
        // we need to check if the character has been seen
        // earlier and if yes we need to check if it is seen
        // again after the string's start has been updated
        if (m.find(A[i]) != m.end() && m[A[i]] > start)
            start = m[A[i]];
        m[A[i]] = i;
        ans = max(ans, i - start);
    }
    return ans;
}
