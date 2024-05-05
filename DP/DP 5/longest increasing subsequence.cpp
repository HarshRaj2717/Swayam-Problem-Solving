class Solution {
    vector<int> mem;
    int memoization(vector<int>& nums, int i = 0, int prev = -1)
    {
        if (i >= nums.size())
            return 0;
        if (mem[prev + 1] != -1)
            return mem[prev + 1];
        int ans = memoization(nums, i + 1, prev);
        if (prev == -1 || nums[prev] < nums[i])
            ans = max(ans, 1 + memoization(nums, i + 1, i));
        mem[prev + 1] = ans;
        return ans;
    }

    int tabulation(vector<int> &nums)
    {
        int ans = 1;
        vector<int> dp(nums.size(), 1);
        for (int i = 0; i < nums.size(); i++)
        {
            for (int j = 0; j < i; j++)
            {
                // dp[j] == LIS from 0->j if nums[j] is included in it for sure
                if (nums[j] >= nums[i])
                    continue;
                dp[i] = max(dp[i], 1 + dp[j]);
                ans = max(ans, dp[i]);
            }
        }
        return ans;
    }

    int binarySearch(vector<int> &nums)
    {
        int ans = -1;
        for (int i: nums)
        {
            if (ans == -1 || nums[ans] < i)
            {
                // cout << ans << ' ' << i << endl;
                ans++;
                nums[ans] = i;
            }
            else
            {
                int s = 0, e = ans;
                int m = s + (e - s) / 2;
                while (s <= e)
                {
                    if (i <= nums[m])
                    {
                        e = m - 1;
                    }
                    else
                    {
                        s = m + 1;
                    }
                    m = s + (e - s) / 2;
                }
                // cout << i  << ' ' << s <<endl;
                nums[s] = i;
            }
        }
        // cout << ans << ' ';

        return ans + 1;
    }

public:
    int lengthOfLIS(vector<int>& nums) {
        // mem = vector<int> (nums.size() + 1, -1);
        // return memoization(nums);

        // return tabulation(nums);

        return binarySearch(nums);
    }
};