#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> Solution::findSubstring(string A, const vector<string> &B);
};

// You are given a string, S, and a list of words, L, that are all of the same length.

// Find all starting indices of substring(s) in S that is a concatenation of each word in L exactly once and without any intervening characters.

// Example :

// S: "barfoothefoobarman"
// L: ["foo", "bar"]
// You should return the indices: [0,9].
// (order does not matter).

vector<int> Solution::findSubstring(string A, const vector<string> &B)
{
    vector<int> ans;
    if (B.empty())
        return ans;
    unordered_map<string, int> dict;
    for (string s : B)
        dict[s]++;
    int n = A.length(), wn = B.front().length();
    for (int i = 0; i < n; i++)
    {
        ;
        unordered_map<string, int> m = dict;
        int count = 0;
        for (int j = i; j < n && j < i + wn * B.size(); j += wn)
        {
            string word = A.substr(j, wn);
            if (m.find(word) == m.end() || m[word] <= 0)
                break;
            count++;
            m[word]--;
            if (count == B.size())
                ans.push_back(i);
        }
    }
}
