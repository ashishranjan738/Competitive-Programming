#include <bits/stdc++.h>
using namespace std;

/*
The idea is to take a pointer at each corner and a variable dir.
The purpose of the dir variable is to tell us on which direction
we have to print. For example:
1. dir==0 -> print from top left corner top right corner.
2. dir==1 -> print from top right corner to bottom right corner.
3. dir==2 -> print from bottom right corner to bottom left corner.
4. dir==3 -> print from bottom right corner to top left corner.
After a printing sequence gets completed we need to decrement the
pointer by 1 from where we have started, and also increment the
direction pointer.
*/

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int m, n;
        cin >> m >> n;
        vector<vector<int>> mat(m, vector<int>(n, 0));
        for (vector<int> &v : mat)
        {
            for (int &i : v)
                cin >> i;
        }
        int sti = 0, stj = 0, endi = m, endj = n, dir = 0;
        while (sti < endi && stj < endj)
        {
            if (dir == 0)
            {
                for (int j = stj; j < endj; j++)
                    cout << mat[sti][j] << " ";
                sti++;
            }
            else if (dir == 1)
            {
                for (int i = sti; i < endi; i++)
                    cout << mat[i][endj - 1] << " ";
                endj--;
            }
            else if (dir == 2)
            {
                for (int j = endj - 1; j >= stj; j--)
                    cout << mat[endi - 1][j] << " ";
                endi--;
            }
            else if (dir == 3)
            {
                for (int i = endi - 1; i >= sti; i--)
                    cout << mat[i][stj] << " ";
                stj++;
            }
            dir = (dir + 1) % 4;
        }

        cout << endl;
    }
    return 0;
}