bool isInside(int x, int y, int A, int B)
{
    return (x >= 0 && x < A && y >= 0 && y < B);
}

string solve(int A, int B, int N, int R, vector<int> &E, vector<int> &F)
{
    vector<vector<bool>> grid(A, vector<bool>(B, true));
    for (int i = 0; i < N; i++)
    {
        for (int x = 0; x < A; x++)
        {
            for (int y = 0; y < B; y++)
            {
                if (sqrt(pow(E[i] - x, 2) + pow(F[i] - y, 2)) < R)
                {
                    grid[x][y] = false;
                }
            }
        }
    }
    if (!grid[0][0] || !grid[A - 1][B - 1])
    {
        return "NO";
    }
    vector<vector<bool>> visited(A, vector<bool>(B, false));
    queue<pair<int, int>> q;
    q.push({0, 0});
    visited[0][0] = true;
    while (!q.empty())
    {
        pair<int, int> p = q.front();
        q.pop();
        int x = p.first, y = p.second;
        if (x == A - 1 && y == B - 1)
        {
            return "YES";
        }
        for (int dx = -1; dx <= 1; dx++)
        {
            for (int dy = -1; dy <= 1; dy++)
            {
                int nx = x + dx, ny = y + dy;
                if (isInside(nx, ny, A, B) && grid[nx][ny] && !visited[nx][ny])
                {
                    q.push({nx, ny});
                    visited[nx][ny] = true;
                }
            }
        }
    }
    return "NO";
}