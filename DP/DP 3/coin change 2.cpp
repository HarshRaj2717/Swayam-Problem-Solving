class Solution {
public:
    int change(int amount, vector<int>& coins) {
        sort(coins.begin(), coins.end());
        vector<int> dp(amount + 1, 0);
        dp[0] = 1;
        for (int j = 0; j < coins.size(); j++) {
            // dp[i] => no. of combinations for amount == i witgh coins[0]->coins[j]
            for (int i = 1; i <= amount; i++) {
                int curCoin = coins[j];
                if (i - curCoin < 0)
                    continue;
                dp[i] += dp[i - curCoin];
            }
        }
        return dp[amount];
    }
};