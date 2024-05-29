#include <bits/stdc++.h>

using namespace std;

int solver(int n)
{
    if (n == 0)
        return 0;
    int MOD = 1e9 + 7;
    vector<int> dp(n + 1, 0);
    dp[0] = 1;
    dp[1] = 1;

    for (int i = 2; i <= n; i++)
    {
        for (int j = i - 1; j >= max(0, i - 6); j--)
        {
            dp[i] = (dp[i] + dp[j]) % MOD;
        }
    }

    return dp[n] % MOD;
}

int main()
{
    int n;
    cin >> n;
    cout << solver(n) << endl;
    return 0;
}