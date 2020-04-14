// Given a List of N number a1,a2,a3........an, You have to find smallest number from the List that is repeated in the List exactly K number of times.

// Input Format

// First Line of Input Contain Single Value N, Size of List
// Second Line of Input Contain N Space Separated Integers
// Third Line of Input Contain Single Value K

// Output Format

// Smallest Integer Value That is Repeated Exactly K Number of Time

// Constraints

// 0 < N < 100001
// 0 <= K < 100001
// 0 <= ai < 100001
// NOTE
// There Will Be Atleast One Variable Which Is Repeated K Times

// SAMPLE INPUT
// 5
// 2 2 1 3 1
// 2
// SAMPLE OUTPUT
// 1

#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    map<int, int> m;
    for (int i = 0; i < n; i++)
    {
        int a;
        cin >> a;
        m[a]++;
    }
    int k;
    cin >> k;
    for (auto it = m.begin(); it != m.end(); it++)
    {
        if (it->second == k)
        {
            cout << it->first << "\n";
            break;
        }
    }
    return 0;
}
// Hint:
// Maintain a map of occurences. Since the keys in the map are traversed in ascending order we can compare the occurences and print it.