class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        sort(coins.begin(), coins.end());
        vector<int> dp(amount + 1, -1);
        dp[0] = 0;
        for (int i = 1; i <= amount; i++) {
            // dp[i] => min coins needed for amount == i
            for (int j = 0; j < coins.size() && coins[j] <= i; j++) {
                int curCoin = coins[j];
                if (dp[i - curCoin] == -1)
                    continue;
                dp[i] = (dp[i] == -1) ? 1 + dp[i - curCoin] : min(dp[i], 1 + dp[i - curCoin]);
            }
        }
        return dp[amount];
    }
};