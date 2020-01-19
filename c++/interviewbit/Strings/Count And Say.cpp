#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string Solution::countAndSay(int A);
};

// The count-and-say sequence is the sequence of integers beginning as follows:

// 1, 11, 21, 1211, 111221, ...
// 1 is read off as one 1 or 11.
// 11 is read off as two 1s or 21.

// 21 is read off as one 2, then one 1 or 1211.

// Given an integer n, generate the nth sequence.

// Note: The sequence of integers will be represented as a string.

// Example:

// if n = 2,
// the sequence is 11.

#include <string>
string generateNextSequence(string a)
{
    if (a == "")
        return "1";
    char previous = a[0];
    int occurrence = 1;
    string b;
    for (int i = 1; i < a.length(); i++)
    {
        char c = a[i];
        if (previous != c)
        {
            b += to_string(occurrence);
            b.push_back(previous);
            occurrence = 0;
        }
        occurrence++;
        previous = c;
    }
    if (occurrence > 0)
    {
        b += to_string(occurrence);
        b.push_back(previous);
    }
    return b;
}
string Solution::countAndSay(int A)
{
    string ans;
    while (A--)
        ans = generateNextSequence(ans);
    return ans;
}
