class Solution {
    int recur(vector<int>& nums, int target, int cur = 0)
    {
        if (target == 0)
            return 0;
        if (target < 0 || cur >= nums.size())
            return -1;

        int ans = -1;
        for (int i = cur; i < nums.size(); i++)
        {
            int t = recur(nums, target - nums[i], i + 1);
            if (t == -1)
                continue;
            ans = max(ans, 1 + t);
        }
        return ans;
    }

    vector<vector<int>> mem;
    int memo(vector<int>& nums, int target, int cur = 0)
    {
        if (target == 0)
            return 0;
        if (target < 0 || cur >= nums.size())
            return -1;
        if (mem[target][cur] != -2)
            return mem[target][cur];

        int ans = -1;

        int not_take = memo(nums, target, cur + 1);
        int take = 1 + memo(nums, target - nums[cur], cur + 1);

        if (not_take != -1)
            ans = not_take;
        if (take != 0)
            ans = max(ans, take);

        mem[target][cur] = ans;
        return ans;
    }

    int dp(vector<int>& nums, int target)
    {
        mem = vector<vector<int>> (target + 1, vector<int> (nums.size() + 1, -1));

        for (int i = 0; i <= nums.size(); i++)
        {
            mem[0][i] = 0;
        }

        for (int i = 1; i <= target; i++)
        {
            for (int j = 1; j <= nums.size(); j++)
            {
                // dp[i][j] ==> length of longest subsequce from starting `j` elements of nums that sum up to `i`
                int take = (i - nums[j-1] < 0 || mem[i - nums[j-1]][j-1] == -1) ? -1 : 1 + mem[i - nums[j-1]][j-1];
                int not_take = mem[i][j-1];
                mem[i][j] = max(take, not_take);
            }
        }

        return mem[target][nums.size()];
    }
public:
    int lengthOfLongestSubsequence(vector<int>& nums, int target) {
        // return recur(nums, target);

        // mem = vector<vector<int>> (target + 1, vector<int> (nums.size() + 1, -2));
        // return memo(nums, target);


        return dp(nums, target);
    }
};