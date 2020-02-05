#include <bits/stdc++.h>
using namespace std;
int solve(vector<int> coins, int sum)
{
    vector<int> dp(sum + 1, INT_MAX);
    dp[0] = 0;
    for (int i = 0; i <= sum; i++)
    {
        for (int coin : coins)
        {
            if (i - coin >= 0 && dp[i - coin] != INT_MAX)
                dp[i] = min(dp[i], 1 + dp[i - coin]);
        }
    }
    return dp[sum];
}

int main()
{
    vector<int> coins{1, 5, 6, 9};
    int sum = 11;
    cout << solve(coins, sum);
    return 0;
}