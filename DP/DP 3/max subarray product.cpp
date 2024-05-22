class Solution {
public:
    int maxProduct(vector<int>& nums) {
        vector<int> save = nums;
        int ans = nums[0];
        if (nums[0] == 0)
            nums[0] = 1;
        for (int i = 1; i < nums.size(); i++) {
            nums[i] = nums[i] * nums[i-1];
            ans = max(ans, nums[i]);
            if (nums[i] == 0)
                nums[i] = 1;        }
        nums = save;
        ans = max(ans, nums[nums.size() - 1]);
        if (nums[nums.size() - 1] == 0)
            nums[nums.size() - 1] = 1;
        for (int i = nums.size() - 2; i >= 0; i--) {
            nums[i] = nums[i] * nums[i+1];
            ans = max(ans, nums[i]);
            if (nums[i] == 0)
                nums[i] = 1;
        }
        return ans;
    }
};