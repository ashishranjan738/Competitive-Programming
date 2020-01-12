#include <bits/stdc++.h>
using namespace std;
int add(int a, int b)
{
    while (b)
    {
        int carry = a & b;
        a ^= b;
        b = carry << 1;
    }
    return a;
}

int main()
{
    cout << add(9, 9);
}