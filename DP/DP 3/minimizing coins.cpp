#include <bits/stdc++.h>

using namespace std;

int solver(int n, int x, vector<int> &coins)
{
    if (x == 0)
        return -1;
    vector<int> dp(x + 1, -1);
    dp[0] = 0;

    for (int i = 0; i <= x; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i - coins[j] < 0 || dp[i - coins[j]] == -1)
                continue;
            if (dp[i] == -1)
                dp[i] = 1 + dp[i - coins[j]];
            else
                dp[i] = min(dp[i], 1 + dp[i - coins[j]]);
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