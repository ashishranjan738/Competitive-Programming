#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> Solution::equal(vector<int> &A);
};

// Given an array A of integers, find the index of values that satisfy A + B = C + D, where A,B,C & D are integers values in the array

// Note:

// 1) Return the indices `A1 B1 C1 D1`, so that
//   A[A1] + A[B1] = A[C1] + A[D1]
//   A1 < B1, C1 < D1
//   A1 < C1, B1 != D1, B1 != C1

// 2) If there are more than one solutions,
//    then return the tuple of values which are lexicographical smallest.

// Assume we have two solutions
// S1 : A1 B1 C1 D1 ( these are values of indices int the array )
// S2 : A2 B2 C2 D2

// S1 is lexicographically smaller than S2 iff
//   A1 < A2 OR
//   A1 = A2 AND B1 < B2 OR
//   A1 = A2 AND B1 = B2 AND C1 < C2 OR
//   A1 = A2 AND B1 = B2 AND C1 = C2 AND D1 < D2
// Example:

// Input: [3, 4, 7, 1, 2, 9, 8]
// Output: [0, 2, 3, 5] (O index)
// If no solution is possible, return an empty list.

vector<int> Solution::equal(vector<int> &A)
{
    unordered_map<int, pair<int, int>> m;
    vector<int> ans;
    for (int i = 0; i < A.size(); i++)
    {
        for (int j = i + 1; j < A.size(); j++)
        {
            int sum = A[i] + A[j];
            if (m.find(sum) == m.end())
            {
                m[sum] = make_pair(i, j);
            }
            else
            {
                int pi = m[sum].first;
                int pj = m[sum].second;

                if (pi != i && pi != j && pj != i && pj != j)
                {
                    vector<int> tans{pi, pj, i, j};
                    if (ans.size())
                    {
                        for (int x = 0; x < tans.size(); x++)
                        {
                            // if the currently value is less than
                            // the temporary answer then it is already
                            // lexicographically sorted
                            if (ans[x] < tans[x])
                                break;
                            if (ans[x] > tans[x])
                            {
                                ans = tans;
                                break;
                            }
                        }
                    }
                    else
                        ans = tans;
                }
            }
        }
    }
    return ans;
}
