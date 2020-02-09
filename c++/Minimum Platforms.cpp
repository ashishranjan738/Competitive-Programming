#include <bits/stdc++.h>
using namespace std;
struct train
{
    int arr, dept;
};
bool comp(train &a, train &b)
{
    return a.arr < b.arr;
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<train> trains(n);
        for (int i = 0; i < n; i++)
            cin >> trains[i].arr;
        for (int i = 0; i < n; i++)
            cin >> trains[i].dept;
        priority_queue<int, vector<int>, greater<int>> q;
        sort(trains.begin(), trains.end(), comp);
        q.push(trains[0].dept);
        int platform = 1;
        for (int i = 1; i < n; i++)
        {
            while (!q.empty() && q.top() < trains[i].arr)
                q.pop();
            q.push(trains[i].dept);
            int size = q.size();
            platform = max(platform, size);
        }
        cout << platform << endl;
    }

    return 0;
}