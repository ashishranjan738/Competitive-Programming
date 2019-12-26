#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string Solution::fractionToDecimal(int A, int B);
};

// Given two integers representing the numerator and denominator of a fraction, return the fraction in string format.

// If the fractional part is repeating, enclose the repeating part in parentheses.

// Example :

// Given numerator = 1, denominator = 2, return "0.5"
// Given numerator = 2, denominator = 1, return "2"
// Given numerator = 2, denominator = 3, return "0.(6)"

string Solution::fractionToDecimal(int A, int B)
{
    if (!A)
        return "0";
    if (!B)
        return "";
    string ans;
    // if any of the numerator or denominator is
    // negative we need to insert the negative sign
    if (A > 0 ^ B > 0)
        ans += "-";

    long int n = labs(A), d = labs(B), r = n % d;
    ans += to_string(n / d);
    // Taking a map of remainder and length() of ans
    // to insert the brackets
    unordered_map<int, int> m;

    // if the remainder > 0 then we need to insert the
    // decimal point
    if (r)
        ans += ".";

    while (r)
    {
        // if we are seeing the remainder again
        // that means the digits have started reccuring
        if (m.find(r) != m.end())
        {
            ans.insert(m[r], "(");
            ans += ")";
            break;
        }
        m[r] = ans.length();
        r *= 10;
        ans += to_string(r / d);
        r = (long)r % d;
    }
    return ans;
}
