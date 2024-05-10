class DisjointSet
{
public:
    vector<int> parent, size, rank;
    DisjointSet(int n)
    {
        rank.resize(n + 1, 0);
        parent.resize(n + 1);
        size.resize(n + 1);
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
        }
        else
        {
            size[pu] += size[pv];
            parent[pv] = pu;
        }
    }
};

int minSwapsCouples(vector<int> &row)
{
    int count = 0;
    int n = row.size();
    DisjointSet ds(n);
    for (int i = 0; i < n; i += 2)
    {
        ds.UnionbySize(i, i + 1);
    }
    for (int i = 0; i < n; i += 2)
    {
        int left = ds.findParent(row[i]);
        int right = ds.findParent(row[i + 1]);
        if (left != right)
        {
            ds.UnionbySize(left, right);
            count++;
        }
    }
    return count;
}