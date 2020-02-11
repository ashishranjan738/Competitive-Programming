#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int maxSum = INT_MIN, maxSumSoFar = 0;
        for (int i = 0; i < n; i++)
        {
            int x;
            cin >> x;
            maxSumSoFar += x;
            maxSum = max(maxSum, maxSumSoFar);
            if (maxSumSoFar < 0)
                maxSumSoFar = 0;
        }
        cout << maxSum << endl;
    }
    return 0;
}