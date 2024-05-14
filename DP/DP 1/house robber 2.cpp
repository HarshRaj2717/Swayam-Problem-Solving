class Solution {
    int recur(vector<int>& nums, int i = 0, bool pickedFirst = false) {
        if (i >= nums.size() || (pickedFirst && i == nums.size() - 1))
            return 0;

        return max((nums[i] + recur(nums, i + 2, i == 0 || pickedFirst)), recur(nums, i + 1, pickedFirst));
    }

    vector<vector<int>> mem;
    int memo(vector<int>& nums, int i = 0, bool pickedFirst = false) {
        if (i >= nums.size() || (pickedFirst && i == nums.size() - 1))
            return 0;
        if (mem[pickedFirst][i] != -1)
            return mem[pickedFirst][i];

        mem[pickedFirst][i] = max((nums[i] + memo(nums, i + 2, i == 0 || pickedFirst)), memo(nums, i + 1, pickedFirst));
        return mem[pickedFirst][i];
    }

    int dp(vector<int>& nums) {
        mem = vector<vector<int>> (2, vector<int> (nums.size() + 1, 0));
        int i = nums.size() - 1;
        mem[0][i] = 0;
        mem[1][i] = nums[i];
        i--;

        for (; i >= 0; i--) {
            mem[0][i] = max((nums[i] + mem[0][i + 2]), mem[0][i + 1]);

            if (i != 0)
                mem[1][i] = max((nums[i] + mem[1][i + 2]), mem[1][i + 1]);
            else
                mem[1][i] = max(mem[1][i + 2], mem[1][i + 1]);
        }

        return max(mem[0][0], mem[1][0]);
    }
public:
    int rob(vector<int>& nums) {
        // return recur(nums);

        // mem = vector<vector<int>> (2, vector<int> (nums.size(), -1));
        // return memo(nums);

        return dp(nums);
    }
};