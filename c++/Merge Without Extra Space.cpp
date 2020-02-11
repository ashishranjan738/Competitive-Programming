#include <bits/stdc++.h>
using namespace std;
#include <bits/stdc++.h>
using namespace std;
void merge(int *a, int n, int *b, int m)
{
    //Building a min_heap [takes O(m)]
    make_heap(b, b + m, greater<int>());

    //This step takes [O(nlogm)]
    for (int i = 0; i < n; i++)
    {
        if (a[i] > b[0])
        {
            //popping from min_heap
            pop_heap(b, b + m, greater<int>());

            //Swapping the elements
            int tmp = a[i];
            a[i] = b[m - 1];
            b[m - 1] = tmp;

            //pushing into min_heap
            push_heap(b, b + m, greater<int>());
        }
    }
    //Converting into max_heap b'coz sort_heap() on min heap sorts the array in decreasing order
    //This step is [O(m)]
    make_heap(b, b + m); //It's a max_heap

    //This step is O(mlogm)
    sort_heap(b, b + m); //Prooduces array in increasing order
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;
        int *v1 = new int[n], *v2 = new int[m];
        for (int i = 0; i < n; i++)
            cin >> v1[i];
        for (int j = 0; j < n; j++)
            cin >> v2[j];
        merge(v1, n, v2, m);
        for (int i = 0; i < n; i++)
            cout << v1[i] << " ";
        for (int j = 0; j < m; j++)
            cout << v2[j] << " ";
        cout << endl;
    }
    return 0;
}