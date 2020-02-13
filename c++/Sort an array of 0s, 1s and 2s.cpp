#include <bits/stdc++.h>
using namespace std;
/*
    This problem is very similar to Dutch National Flag problem.
    The key idea is to maintain a pointer i,j and k for 0s,1s and 2s.
    We need to arrange 0s and 2s in correct place then 1s will automatically
    get arranged in the correct place. We start i and j pointer from
    the starting of the array index and k from ending of rhe array index and
    iterate until all the 2s and 0s are in correct position.
*/
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
        int i = 0, j = 0, k = n - 1;
        while (j <= k)
        {
            if (v[j] == 0)
            {
                swap(v[j], v[i]);
                i++;
                j++;
            }
            else if (v[j] == 1)
                j++;
            else
            {
                swap(v[j], v[k]);
                k--;
            }
        }
        for (int i : v)
            cout << i << " ";
        cout << endl;
    }
    return 0;
}