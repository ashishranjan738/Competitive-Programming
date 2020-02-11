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
        for (int &i : v)
            cin >> i;
        sort(v.begin(), v.end());
        int count = 0;
        for (int k = n - 1; k > 1; k--)
        {
            int c = v[k];
            int i = 0, j = k - 1;
            while (i < j)
            {
                int x = v[i] + v[j];
                if (c == x)
                {
                    count++;
                    i++;
                    j--;
                }
                else if (x < c)
                    i++;
                else
                    j--;
            }
        }
        if (count == 0)
            cout << "-1";
        else
            cout << count;
        cout << endl;
    }
    return 0;
}