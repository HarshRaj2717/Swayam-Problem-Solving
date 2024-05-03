vector<vector<int>> nearest(vector<vector<int>> grid)
{
    int n = grid.size(), m = grid[0].size();
    queue<pair<int, int>> q;
    vector<vector<int>> res(n, vector<int>(m, -1));
    vector<vector<int>> direction = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (grid[i][j] == 1)
            {
                q.push({i, j});
                res[i][j] = 0;
            }
        }
    }
    while (!q.empty())
    {
        pair<int, int> cur = q.front();
        q.pop();
        for (auto &dir : direction)
        {
            int ni = cur.first + dir[0], nj = cur.second + dir[1];
            if (ni >= 0 && ni < n && nj >= 0 && nj < m && res[ni][nj] == -1)
            {
                res[ni][nj] = res[cur.first][cur.second] + 1;
                q.push({ni, nj});
            }
        }
    }
    return res;
}