#include <bits/stdc++.h>

using namespace std;

int solver(int n, int x, vector<int> &coins)
{
    int MOD = 1e9 + 7;
    if (x == 0)
        return 0;
    vector<int> dp(x + 1, 0);
    dp[0] = 1;

    for (int j = 0; j < n; j++)
    {
        for (int i = 0; i <= x; i++)
        {
            if (i - coins[j] < 0)
                continue;
            dp[i] = (dp[i] + dp[i - coins[j]]) % MOD;
        }
    }

    return dp[x];
}

int main()
{
    int n, x;
    cin >> n;
    cin >> x;
    vector<int> coins(n);
    for (int i = 0; i < n; i++)
        cin >> coins[i];

    cout << solver(n, x, coins) << endl;

    return 0;
}