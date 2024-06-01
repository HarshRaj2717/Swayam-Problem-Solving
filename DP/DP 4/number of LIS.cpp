class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        vector<pair<int, int>> dp(nums.size() + 1);
        int ans = 1;
        int lisLen = 1;
        dp[0] = {0, 1};
        dp[1] = {1, 1};

        for (int i = 1; i < nums.size(); i++)
        {
            // dp[i] == {LIS length from 0 to (i-1), no. of such LIS from 0 to (i-1)}
            // *(i-1)th element included
            int cnt = 1;
            int maxLen = 0;
            for (int j = 0; j < i; j++)
            {
                if (nums[i] <= nums[j])
                    continue;
                if (dp[j+1].first < maxLen)
                    continue;
                if (dp[j+1].first > maxLen)
                {
                    cnt = 0;
                    maxLen = dp[j+1].first;
                }
                cnt += dp[j+1].second;
            }
            dp[i+1] = {maxLen + 1, cnt};
            if (lisLen == maxLen + 1)
            {
                ans += cnt;
            }
            else if (lisLen < maxLen + 1)
            {
                ans = cnt;
                lisLen = maxLen + 1;
            }
        }

        return ans;
    }
};