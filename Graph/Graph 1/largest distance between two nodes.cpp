int ans = 0;

int solver(vector<vector<int>> &adj, int root)
{
    int maxh = 0;
    for (int i: adj[root])
    {
        int cur = solver(adj, i);
        ans = max(ans, maxh + cur);
        maxh = max(maxh, cur);
    }
    return maxh + 1;
}

int Solution::solve(vector<int> &A) {
    vector<vector<int>> adj(A.size());
    int root = 0;
    for (int i = 0; i < A.size(); i++)
    {
        if (A[i] == -1)
        {
            root = i;
            continue;
        }
        adj[A[i]].push_back(i);
    }
    ans = 0;
    solver(adj, root);
    return ans;
}
