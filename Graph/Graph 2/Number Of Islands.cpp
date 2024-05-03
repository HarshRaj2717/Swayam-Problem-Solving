void removeisland(vector<vector<char>> &grid, int i, int j)
{
    if (i < 0 || i >= grid.size() || j < 0 || j >= grid[0].size() || grid[i][j] != '1')
        return;
    grid[i][j] = '0';
    removeisland(grid, i - 1, j);
    removeisland(grid, i + 1, j);
    removeisland(grid, i, j - 1);
    removeisland(grid, i, j + 1);
}

int numIslands(vector<vector<char>> &grid)
{
    if (grid.size() == 0)
        return 0;
    int cnt = 0;
    for (int i = 0; i < grid.size(); i++)
    {
        for (int j = 0; j < grid[i].size(); j++)
        {
            if (grid[i][j] == '1')
            {
                removeisland(grid, i, j);
                cnt++;
            }
        }
    }
    return cnt;
}
