// https://www.hackerearth.com/practice/data-structures/arrays/1-d/practice-problems/algorithm/can-you-solve-it/

#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> v(n);
        for (int &a : v)
            cin >> a;
        int min1 = INT_MAX, min2 = INT_MAX, max1 = INT_MIN, max2 = INT_MIN;
        for (int i = 0; i < n; i++)
        {
            min1 = min(min1, v[i] + i);
            max1 = max(max1, v[i] + i);
            min2 = min(min2, v[i] - i);
            max2 = max(max2, v[i] - i);
        }
        cout << max(max1 - min1, max2 - min2) << "\n";
    }

    return 0;
}