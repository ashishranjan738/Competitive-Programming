#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int Solution::longestValidParentheses(string A);
};

// Given a string A containing just the characters ’(‘ and ’)’.

// Find the length of the longest valid (well-formed) parentheses substring.

// Input Format:

// The only argument given is string A.
// Output Format:

// Return the length of the longest valid (well-formed) parentheses substring.
// Constraints:

// 1 <= length(A) <= 750000
// For Example

// Input 1:
//     A = "(()"
// Output 1:
//     2
//     Explanation 1:
//         The longest valid parentheses substring is "()", which has length = 2.

// Input 2:
//     A = ")()())"
// Output 2:
//     4
//     Explanation 2:
//         The longest valid parentheses substring is "()()", which has length = 4.

int Solution::longestValidParentheses(string A)
{
    stack<int> st;
    int ans = 0;
    st.push(-1);
    for (int i = 0; i < A.length(); i++)
    {
        // when a valid paranthesis is met
        if (A[i] == ')' && st.top() >= 0 && A[st.top()] == '(')
        {
            st.pop(); // length of the substring is j-(i-1)
            ans = max(ans, i - st.top());
        }
        else
            st.push(i); // pushing both '(' and ')' when ')' doesn't form a valid parenthesis
    }
    return ans;
}
