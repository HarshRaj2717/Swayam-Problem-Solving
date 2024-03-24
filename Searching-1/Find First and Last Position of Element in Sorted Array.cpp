class Solution
{
public:
    int solve_lower(vector<int> &n, int e)
    {
        int l = 0, r = n.size() - 1, f = -1;
        while (l <= r)
        {
            int m = l + (r - l) / 2;
            if (n[m] >= e)
            {
                r = m - 1;
                if (n[m] == e)
                    f = m;
            }
            else
                l = m + 1;
        }
        return f;
    }
    int solve_upper(vector<int> &n, int e)
    {
        int l = 0, r = n.size() - 1, f = -1;
        while (l <= r)
        {
            int m = l + (r - l) / 2;
            if (n[m] <= e)
            {
                l = m + 1;
                if (n[m] == e)
                    f = m;
            }
            else
                r = m - 1;
        }
        return f;
    }
    vector<int> searchRange(vector<int> &nums, int target)
    {
        int l = solve_upper(nums, target);
        int r = solve_lower(nums, target);
        vector<int> ans;
        ans.push_back(r);
        ans.push_back(l);
        return ans;
    }
};