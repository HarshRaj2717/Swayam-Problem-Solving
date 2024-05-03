bool solve(int row, int col, vector<vector<int>> &vis, vector<vector<int>> &grid, int n, int m)
{
    vis[row][col] = 1;
    if (row == n - 1 && col == m - 1)
        return true;

    if (grid[row][col] == 1 && col - 1 >= 0 && (grid[row][col - 1] == 4 || grid[row][col - 1] == 6 || grid[row][col - 1] == 1) && vis[row][col - 1] == 0)
    {
        if (solve(row, col - 1, vis, grid, n, m))
            return true;
    }
    if (grid[row][col] == 1 && col + 1 < m && (grid[row][col + 1] == 3 || grid[row][col + 1] == 5 || grid[row][col + 1] == 1) && vis[row][col + 1] == 0)
    {
        if (solve(row, col + 1, vis, grid, n, m))
            return true;
    }
    if (grid[row][col] == 2 && row + 1 < n && (grid[row + 1][col] == 5 || grid[row + 1][col] == 6 || grid[row + 1][col] == 2) && vis[row + 1][col] == 0)
    {
        if (solve(row + 1, col, vis, grid, n, m))
            return true;
    }
    if (grid[row][col] == 2 && row - 1 >= 0 && (grid[row - 1][col] == 4 || grid[row - 1][col] == 3 || grid[row - 1][col] == 2) && vis[row - 1][col] == 0)
    {
        if (solve(row - 1, col, vis, grid, n, m))
            return true;
    }
    if (grid[row][col] == 3 && col - 1 >= 0 && (grid[row][col - 1] == 1 || grid[row][col - 1] == 6 || grid[row][col - 1] == 4) && vis[row][col - 1] == 0)
    {
        if (solve(row, col - 1, vis, grid, n, m))
            return true;
    }
    if (grid[row][col] == 3 && row + 1 < n && (grid[row + 1][col] == 2 || grid[row + 1][col] == 6 || grid[row + 1][col] == 5) && vis[row + 1][col] == 0)
    {
        if (solve(row + 1, col, vis, grid, n, m))
            return true;
    }
    if (grid[row][col] == 4 && col + 1 < m && (grid[row][col + 1] == 1 || grid[row][col + 1] == 3 || grid[row][col + 1] == 5) && vis[row][col + 1] == 0)
    {
        if (solve(row, col + 1, vis, grid, n, m))
            return true;
    }
    if (grid[row][col] == 4 && row + 1 < n && (grid[row + 1][col] == 2 || grid[row + 1][col] == 5 || grid[row + 1][col] == 6) && vis[row + 1][col] == 0)
    {
        if (solve(row + 1, col, vis, grid, n, m))
            return true;
    }
    if (grid[row][col] == 5 && col - 1 >= 0 && (grid[row][col - 1] == 1 || grid[row][col - 1] == 6 || grid[row][col - 1] == 4) && vis[row][col - 1] == 0)
    {
        if (solve(row, col - 1, vis, grid, n, m))
            return true;
    }
    if (grid[row][col] == 5 && row - 1 >= 0 && (grid[row - 1][col] == 2 || grid[row - 1][col] == 3 || grid[row - 1][col] == 4) && vis[row - 1][col] == 0)
    {
        if (solve(row - 1, col, vis, grid, n, m))
            return true;
    }
    if (grid[row][col] == 6 && col + 1 < m && (grid[row][col + 1] == 1 || grid[row][col + 1] == 3 || grid[row][col + 1] == 5) && vis[row][col + 1] == 0)
    {
        if (solve(row, col + 1, vis, grid, n, m))
            return true;
    }
    if (grid[row][col] == 6 && row + 1 < n && (grid[row + 1][col] == 2 || grid[row + 1][col] == 3 || grid[row + 1][col] == 4) && vis[row + 1][col] == 0)
    {
        if (solve(row + 1, col, vis, grid, n, m))
            return true;
    }
    return false;
}
bool hasValidPath(vector<vector<int>> &grid)
{
    int n = grid.size();
    int m = grid[0].size();
    vector<vector<int>> vis(n, vector<int>(m, 0));
    return solve(0, 0, vis, grid, n, m);
}