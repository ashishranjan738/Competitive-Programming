#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> Solution::grayCode(int A);
};

// The gray code is a binary numeral system where two successive values differ in only one bit.

// Given a non-negative integer n representing the total number of bits in the code, print the sequence of gray code. A gray code sequence must begin with 0.

// For example, given n = 2, return [0,1,3,2]. Its gray code sequence is:

// 00 - 0
// 01 - 1
// 11 - 3
// 10 - 2
// There might be multiple gray code sequences possible for a given n.
// Return any such sequence.

int binaryToDecimal(string n)
{
    string num = n;
    int dec_value = 0;

    // Initializing base value to 1, i.e 2^0
    int base = 1;

    int len = num.length();
    for (int i = len - 1; i >= 0; i--)
    {
        if (num[i] == '1')
            dec_value += base;
        base = base * 2;
    }

    return dec_value;
}

void solve(int n, int i, vector<int> &ans, vector<string> &vals)
{
    if (i == n)
    {
        for (string c : vals)
        {
            ans.push_back(binaryToDecimal(c));
        }
        return;
    }
    vector<string> tvals(vals.rbegin(), vals.rend());
    for (string &a : vals)
        a = "0" + a;
    for (string &a : tvals)
        a = "1" + a;
    vals.insert(vals.end(), tvals.begin(), tvals.end());
    solve(n, i + 1, ans, vals);
}
vector<int> Solution::grayCode(int A)
{
    vector<int> ans;
    vector<string> vals;
    vals.push_back("0");
    vals.push_back("1");
    solve(A, 1, ans, vals);
    return ans;
}