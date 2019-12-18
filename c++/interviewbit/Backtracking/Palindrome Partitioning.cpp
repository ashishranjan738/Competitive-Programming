#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<vector<string>> Solution::partition(string A);
};
// Given a string s, partition s such that every string of the partition is a palindrome.

// Return all possible palindrome partitioning of s.

// For example, given s = "aab",
// Return

//   [
//     ["a","a","b"]
//     ["aa","b"],
//   ]
//  Ordering the results in the answer : Entry i will come before Entry j if :
// len(Entryi[0]) < len(Entryj[0]) OR
// (len(Entryi[0]) == len(Entryj[0]) AND len(Entryi[1]) < len(Entryj[1])) OR
// *
// *
// *
// (len(Entryi[0]) == len(Entryj[0]) AND … len(Entryi[k] < len(Entryj[k]))
// In the given example,
// ["a", "a", "b"] comes before ["aa", "b"] because len("a") < len("aa")

map<string, bool> m;

bool isPalindrome(string s)
{
    if (m.find(s) != m.end())
        return m[s];
    int i = 0;
    int j = s.length() - 1;
    while (i < j)
    {
        if (s[i++] != s[j--])
            return m[s] = false;
    }
    return m[s] = true;
}
void solve(string &A, int start, vector<vector<string>> &ans, vector<string> &tans)
{
    if (start > A.size())
        return;
    if (start == A.size())
    {
        ans.push_back(tans);
        return;
    }
    for (int i = start; i < A.size(); i++)
    {
        string substr = A.substr(start, i - start + 1);
        if (isPalindrome(substr))
        {
            tans.push_back(substr);
            solve(A, i + 1, ans, tans);
            tans.pop_back();
        }
    }
}

vector<vector<string>> Solution::partition(string A)
{
    vector<string> tans;
    vector<vector<string>> ans;
    solve(A, 0, ans, tans);
    return ans;
}
