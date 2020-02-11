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
        int sum = n * (n + 1) / 2;
        int arraySum = 0;
        for (int i = 0; i < n - 1; i++)
        {
            int x;
            cin >> x;
            arraySum += x;
        }
        cout << sum - arraySum << endl;
    }
    return 0;
}