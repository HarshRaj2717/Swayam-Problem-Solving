class Solution {
    int recursive(vector<int> &nums, int i = 0) { 
        if (i >= nums.size() - 1)
            return 0;

        int ans = INT_MAX - 1;
        for (int j = 1; j <= nums[i] && (i + j) < nums.size(); j++)
        {
            ans = min(ans, 1 + recursive(nums, i + j));
        }

        return ans;
    }

    vector<int> mem;
    int memoization(vector<int> &nums, int i = 0) {
        if (i >= nums.size() - 1)
            return 0;
        if (mem[i] != -1)
            return mem[i];

        int ans = INT_MAX - 1;
        for (int j = 1; j <= nums[i] && (i + j) < nums.size(); j++)
        {
            ans = min(ans, 1 + memoization(nums, i + j));
        }

        mem[i] = ans;
        return ans;
    }

    int dp(vector<int> &nums) {
        mem = vector<int> (nums.size(), INT_MAX - 1);

        int cur = nums.size() - 1;
        mem[cur] = 0;
        cur--;

        for (; cur >= 0; cur--)
        {
            for (int j = 1; j <= nums[cur] && (cur + j) < nums.size(); j++)
            {
                mem[cur] = min(mem[cur], 1 + mem[cur + j]);
            }
        }

        return mem[0];
    }

    int greedy(vector<int> &nums) {
        int ans = 0, cur_end = 0, cur_farthest = 0;
        for (int i = 0; i < nums.size() - 1; i++)
        {
            cur_farthest = max(cur_farthest, i + nums[i]);
            if (i == cur_end)
            {
                ans++;
                cur_end = cur_farthest;
            }
        }
        return ans;
    }

public:
    int jump(vector<int>& nums) {
        // if we are at some point then go from i->j and get the min steps from
        // reaching from there to the end.. return that min thingy
        // return recursive(nums);

        // mem = vector<int>(nums.size(), -1);
        // return memoization(nums);

        // return dp(nums);

        return greedy(nums);
    }
};