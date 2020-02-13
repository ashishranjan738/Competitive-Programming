// #include <bits/stdc++.h>
// using namespace std;
// int main()
// {
//     int t;
//     cin >> t;
//     while (t--)
//     {
//         int n;
//         cin >> n;
//         vector<int> v(n), s(n);
//         int sum = 0;
//         for (int i = 0; i < n; i++)
//         {
//             cin >> v[i];
//             sum += v[i];
//             s[i] = sum;
//         }
//         int ans = -1;
//         for (int i = 1; i < n - 1; i++)
//         {
//             if (s[i - 1] == s[n - 1] - s[i])
//             {
//                 ans = i + 1;
//                 break;
//             }
//         }
//         if (v.size() == 1)
//             cout << 1;
//         else
//             cout << ans;
//         cout << endl;
//     }
//     return 0;
// }


/*
The idea is to maintain a leftSum and rightSum. If leftSum and rightSum
matches return the position. 
*/
#include <bits/stdc++.h>
using namespace std;
int findEquillibrium(vector<int> &v)
{
    int n = v.size();
    int rightSum = 0, leftSum = 0;
    for (int i : v)
        rightSum += i;
    for (int i = 0; i < n; i++)
    {
        rightSum -= v[i];
        if (leftSum == rightSum)
        {
            return i + 1;
        }

        leftSum += v[i];
    }
    return -1;
}
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
        cout << findEquillibrium(v) << endl;
    }
}