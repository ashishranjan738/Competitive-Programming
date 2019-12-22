#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> Solution::lszero(vector<int> &A);
};

// Find the largest continuous sequence in a array which sums to zero.

// Example:

// Input:  {1 ,2 ,-2 ,4 ,-4}
// Output: {2 ,-2 ,4 ,-4}

//  NOTE : If there are multiple correct answers, return the sequence which occurs first in the array.

vector<int> Solution::lszero(vector<int> &A)
{
    unordered_map<int, int> m;
    int sum = 0;
    vector<int> ans;
    m[0] = 0;
    for (int i = 1; i <= A.size(); i++)
    {
        sum += A[i - 1];
        if (m.find(sum) != m.end())
        {
            vector<int> tans(A.begin() + m[sum], A.begin() + i);
            if (tans.size() > ans.size())
                ans = tans;
        }
        else
        {
            m[sum] = i;
        }
    }
    return ans;
}

// Refernce:
// https://www.youtube.com/watch?v=hLcYp67wCcM
