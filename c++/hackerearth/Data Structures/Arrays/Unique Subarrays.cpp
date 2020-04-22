// https://www.hackerearth.com/practice/data-structures/arrays/1-d/practice-problems/algorithm/unique-subarrays/

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
        vector<int> v(n);
        for (int &a : v)
            cin >> a;
        long long int ans = 0;
        set<int> s;
        for (int i = 0, j = 0; i < n; i++)
        {
            for (; j < n && !s.count(v[j]); j++)
                s.insert(v[j]);
            ans += 1LL * (j - i) * (j - i + 1) / 2;
            s.erase(v[i]);
        }
        cout << ans << "\n";
    }
}