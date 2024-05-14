class Solution {
    int recur(vector<int>& nums, int i = 0) {
        if (i >= nums.size())
            return 0;

        return max((nums[i] + recur(nums, i + 2)), recur(nums, i + 1));
    }

    vector<int> mem;
    int memo(vector<int>& nums, int i = 0) {
        if (i >= nums.size())
            return 0;
        if (mem[i] != -1)
            return mem[i];

        mem[i] = max((nums[i] + memo(nums, i + 2)), memo(nums, i + 1));
        return mem[i];
    }

    int dp(vector<int>& nums) {
        mem = vector<int> (nums.size() + 1, 0);
        // mem[i] => max money that we can get from i->N-1
        // added an extra index so that we don't need to add extra checks when accessing i + 2 when i == N - 2
        int i = nums.size() - 1;
        mem[i] = nums[i];
        i--;

        for (; i >= 0; i--) {
            mem[i] = max(mem[i + 1], (nums[i] + mem[i + 2]));
        }

        return mem[0];
    }
public:
    int rob(vector<int>& nums) {
        // return recur(nums);

        // mem = vector<int> (nums.size(), -1);
        // return memo(nums);

        return dp(nums);
    }
};