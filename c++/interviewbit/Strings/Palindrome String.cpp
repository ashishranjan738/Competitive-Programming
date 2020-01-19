#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int Solution::isPalindrome(string A);
};

// Given a string, determine if it is a palindrome, considering only alphanumeric characters and ignoring cases.

// Example:

// "A man, a plan, a canal: Panama" is a palindrome.

// "race a car" is not a palindrome.

// Return 0 / 1 ( 0 for false, 1 for true ) for this problem

bool isPalindromeString(string s)
{
    int i = 0, j = s.length() - 1;
    while (i <= j)
        if (s[i++] != s[j--])
            return false;
    return true;
}
int Solution::isPalindrome(string A)
{
    string s = "";
    for (char c : A)
    {
        char lowerC = tolower(c);
        if ((lowerC >= 'a' && lowerC <= 'z') || (lowerC >= '0' && lowerC <= '9'))
            s.push_back(lowerC);
    }
    return isPalindromeString(s);
}
