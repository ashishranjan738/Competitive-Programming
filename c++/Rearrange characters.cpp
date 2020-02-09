#include <bits/stdc++.h>
using namespace std;
bool isPossible(string &s)
{
    unordered_map<char, int> m;
    int maxFrequency = 0;
    for (char c : s)
    {
        m[c]++;
        maxFrequency = max(maxFrequency, m[c]);
    }
    return s.length() - maxFrequency >= maxFrequency;
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string s;
        cin >> s;
        cout << isPossible(s) << endl;
    }
    return 0;
}