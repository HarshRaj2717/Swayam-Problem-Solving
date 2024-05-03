oid EdgesConnectedRegion(vector<vector<char>> &board, int i, int j)
{
    if (i < 0 || i >= board.size() || j < 0 || j >= board[0].size() || board[i][j] != 'O')
        return;
    board[i][j] = '$';
    EdgesConnectedRegion(board, i - 1, j);
    EdgesConnectedRegion(board, i + 1, j);
    EdgesConnectedRegion(board, i, j - 1);
    EdgesConnectedRegion(board, i, j + 1);
}
void solve(vector<vector<char>> &board)
{
    int m = board.size(), n = board[0].size();
    for (int i = 0; i < m; i++)
    {
        if (board[i][0] == 'O')
            EdgesConnectedRegion(board, i, 0);
        if (board[i][n - 1] == 'O')
            EdgesConnectedRegion(board, i, n - 1);
    }
    for (int i = 0; i < n; i++)
    {
        if (board[0][i] == 'O')
            EdgesConnectedRegion(board, 0, i);
        if (board[m - 1][i] == 'O')
            EdgesConnectedRegion(board, m - 1, i);
    }
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            // cout<<board[i][j]<<" ";
            if (board[i][j] == 'O')
                board[i][j] = 'X';
        }
        cout << endl;
    }
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (board[i][j] == '$')
                board[i][j] = 'O';
        }
    }
}