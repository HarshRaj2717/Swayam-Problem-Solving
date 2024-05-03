int orangesRotting(vector<vector<int>> &grid)
{
    int n = grid.size();
    int m = grid[0].size();
    queue<pair<int, int>> q;
    vector<vector<int>> direction = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    int fresh = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (grid[i][j] == 2)
            {
                q.push({i, j});
            }
            else if (grid[i][j] == 1)
            {
                fresh++;
            }
        }
    }
    int time = 0;
    while (!q.empty() && fresh > 0)
    {
        time++;
        int size = q.size();
        while (size--)
        {
            pair<int, int> p = q.front();
            q.pop();
            for (auto d : direction)
            {
                int ni = p.first + d[0];
                int nj = p.second + d[1];
                if (ni >= 0 && ni < n && nj >= 0 && nj < m &&
                    grid[ni][nj] == 1)
                {
                    grid[ni][nj] = 2;
                    q.push({ni, nj});
                    fresh--;
                }
            }
        }
    }
    if (fresh > 0)
    {
        return -1;
    }
    return time;
}