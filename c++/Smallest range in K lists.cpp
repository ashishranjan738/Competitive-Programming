#include <queue>
struct node
{
    int val, i, j;
    bool operator<(node &a)
    {
        return val < a.val;
    }
};
struct compare
{
    bool operator()(node &a, node &b)
    {
        return a.val > b.val;
    }
};
void findSmallestRange(int arr[][N], int n, int k)
{
    priority_queue<node, vector<node>, compare> q;
    int end = INT_MIN, start = INT_MAX, minVal = INT_MAX, maxVal = INT_MIN, currentRange = 0;
    for (int i = 0; i < k; i++)
    {
        q.push(node{arr[i][0], i, 0});
        maxVal = end = max(end, arr[i][0]);
        start = min(start, arr[i][0]);
    }
    currentRange = end - start;
    while (!q.empty())
    {
        node top = q.top();
        q.pop();
        if (maxVal - top.val < currentRange)
        {
            end = maxVal;
            start = top.val;
            currentRange = end - start;
        }
        if (top.j + 1 < n)
        {
            q.push(node{arr[top.i][top.j + 1], top.i, top.j + 1});
            maxVal = max(arr[top.i][top.j + 1], maxVal);
        }
        else
            break;
    }
    cout << start << " " << end << endl;
}