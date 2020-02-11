#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, x;
        cin >> n >> x;
        vector<int> v(n);
        for (int &i : v)
            cin >> i;
        int i = 0, j = 0;
        int sum = 0;
        bool notFound = true;
        while (j < n)
        {
            sum += v[j];
            while (sum > x && i < j)
                sum -= v[i++];
            if (sum == x)
            {
                notFound = false;
                cout << i + 1 << " " << j + 1;
                break;
            }
            j++;
        }
        if (notFound)
            cout << "-1";
        cout << endl;
    }
    return 0;
}