class Solution {
public:
    int minPathCost(vector<vector<int>>& grid, vector<vector<int>>& moveCost) {
        vector<vector<int>> dp(grid.size(), vector<int> (grid[0].size(), INT_MAX));

        for (int i = 0; i < grid[0].size(); i++)
        {
            dp[grid.size() - 1][i] = grid[grid.size() - 1][i];
        }

        for (int i = grid.size() - 2; i >= 0; i--)
        {
            for (int j = 0; j < grid[0].size(); j++)
            {
                for (int k = 0; k < grid[0].size(); k++)
                {
                    dp[i][j] = min(dp[i][j], dp[i+1][k] + moveCost[grid[i][j]][k]);
                }
                dp[i][j] += grid[i][j];
            }
        }

        return *min_element(dp[0].begin(), dp[0].end());
    }
};