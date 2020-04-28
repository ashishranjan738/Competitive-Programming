#include <bits/stdc++.h>
using namespace std;

int clearRange(int n, int i, int j)
{
    int ones = (~0);
    int a = ones << (j + 1);
    int b = (1 << i) - 1;
    int mask = a | b;
    return n & mask;
}

int replaceBits(int n, int m, int i, int j)
{
    int nCleared = clearRange(n, i, j);
    return nCleared | (m << i);
}

int main()
{
    cout << replaceBits(1024, 21, 2, 6);
    return 0;
}