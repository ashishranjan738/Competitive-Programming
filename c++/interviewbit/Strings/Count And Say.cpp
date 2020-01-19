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
    unordered_map<char, int> m;
    char previous = a[0];
    string b;
    m[previous]++;
    for (int i = 1; i < a.length(); i++)
    {
        char c = a[i];
        if (previous != c)
        {
            b += to_string(m[previous]);
            b.push_back(previous);
            m.clear();
        }
        m[c]++;
        previous = c;
    }
    if (m[previous])
    {
        b += to_string(m[previous]);
        b.push_back(previous);
        m.clear();
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
