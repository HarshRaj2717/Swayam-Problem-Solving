bool check(int x, int y, int A, int B)
{
    return (x >= 1 && x <= A && y >= 1 && y <= B);
}

int knight(int A, int B, int C, int D, int E, int F)
{
    vector<pair<int, int>> directions = {{-2, -1}, {-2, 1}, {-1, -2}, {-1, 2}, {1, -2}, {1, 2}, {2, -1}, {2, 1}};

    vector<vector<bool>> visited(A + 1, vector<bool>(B + 1, false));

    queue<pair<pair<int, int>, int>> q;
    q.push({{C, D}, 0});

    while (!q.empty())
    {
        pair<pair<int, int>, int> p = q.front();
        q.pop();

        pair<int, int> cur = p.first;

        int cur_dist = p.second;

        if (cur.first == E && cur.second == F)
        {
            return cur_dist;
        }

        for (pair<int, int> dir : directions)
        {
            int new_x = cur.first + dir.first;
            int new_y = cur.second + dir.second;
            if (check(new_x, new_y, A, B) && !visited[new_x][new_y])
            {
                visited[new_x][new_y] = true;
                q.push({{new_x, new_y}, cur_dist + 1});
            }
        }
    }

    return -1;
}