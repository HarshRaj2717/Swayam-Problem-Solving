class DisjointSet
{
public:
    vector<int> parent, size, rank;
    int maxSize;
    DisjointSet(int n)
    {
        rank.resize(n + 1, 0);
        parent.resize(n + 1);
        size.resize(n + 1);
        maxSize = 0;
        for (int i = 0; i <= n; i++)
        {
            parent[i] = i;
            size[i] = 1;
        }
    }
    int findParent(int u)
    {
        if (u == parent[u])
        {
            return u;
        }
        return parent[u] = findParent(parent[u]);
    }

    void UnionbyRank(int u, int v)
    {
        int pu = findParent(u);
        int pv = findParent(v);
        if (pu == pv)
            return;
        if (rank[pu] < rank[pv])
        {
            parent[pu] = pv;
        }
        else if (rank[pv] < rank[pu])
        {
            parent[pv] = pu;
        }
        else
        {
            parent[pv] = pu;
            rank[pu]++;
        }
    }

    void UnionbySize(int u, int v)
    {
        int pu = findParent(u);
        int pv = findParent(v);
        if (pu == pv)
        {
            return;
        }
        if (size[pu] < size[pv])
        {
            size[pv] += size[pu];
            parent[pu] = pv;
            maxSize = max(maxSize, size[pv]);
        }
        else
        {
            size[pu] += size[pv];
            parent[pv] = pu;
            maxSize = max(maxSize, size[pu]);
        }
    }
};

int maxNumEdgesToRemove(int n, vector<vector<int>> &edges)
{
    DisjointSet alice(n), bob(n);
    int ans = 0;
    for (auto &it : edges)
    {
        if (it[0] == 3)
        {
            if (alice.findParent(it[1]) == alice.findParent(it[2]))
            {
                ans++;
            }
            else
            {
                alice.UnionbySize(it[1], it[2]);
                bob.UnionbySize(it[1], it[2]);
            }
        }
    }

    for (auto &it : edges)
    {
        if (it[0] == 1)
        {
            if (alice.findParent(it[1]) == alice.findParent(it[2]))
            {
                ans++;
            }
            else
            {
                alice.UnionbySize(it[1], it[2]);
            }
        }
        else if (it[0] == 2)
        {
            if (bob.findParent(it[1]) == bob.findParent(it[2]))
            {
                ans++;
            }
            else
            {
                bob.UnionbySize(it[1], it[2]);
            }
        }
    }
    if (alice.maxSize == n and bob.maxSize == n)
        return ans;
    return -1;
}