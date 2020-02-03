#include <bits/stdc++.h>
using namespace std;
int waysToScore(int n)
{
    int arr[n + 1];
    memset(arr, 0, sizeof(arr));
    arr[0] = 1;
    for (int i = 0; i <= n; i++)
    {
        if (i - 3 >= 0)
            arr[i] += arr[i - 3];
        if (i - 5 >= 0)
            arr[i] += arr[i - 5];
        if (i - 10 >= 0)
            arr[i] += arr[i - 10];
    }
    return arr[n];
}
int main()
{
    cout<<waysToScore(13);
    return 0;
}