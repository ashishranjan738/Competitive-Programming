#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<string> Solution::letterCombinations(string A);
};
// Given a digit string, return all possible letter combinations that the number could represent.

// A mapping of digit to letters (just like on the telephone buttons) is given below.
// http://upload.wikimedia.org/wikipedia/commons/thumb/7/73/Telephone-keypad2.svg/200px-Telephone-keypad2.svg.png

// The digit 0 maps to 0 itself.
// The digit 1 maps to 1 itself.

// Input: Digit string "23"
// Output: ["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"].
// Make sure the returned strings are lexicographically sorted.

map<char, string> m;

void solution(vector<string> &ans, string digits, int currentIndex, string previous)
{
    if (currentIndex == digits.length())
    {
        ans.push_back(previous);
        return;
    }
    for (char a : m[digits[currentIndex]])
    {
        previous.push_back(a);
        solution(ans, digits, currentIndex + 1, previous);
        previous.pop_back();
    }
}

vector<string> Solution::letterCombinations(string A)
{
    m['0'] = "0";
    m['1'] = "1";
    m['2'] = "abc";
    m['3'] = "def";
    m['4'] = "ghi";
    m['5'] = "jkl";
    m['6'] = "mno";
    m['7'] = "pqrs";
    m['8'] = "tuv";
    m['9'] = "wxyz";
    vector<string> ans;
    solution(ans, A, 0, "");
    return ans;
}
