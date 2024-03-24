int solveupper(vector<int> &ar, int mi)
{
    int l = 0, r = ar.size() - 1, ans = 0;
    while (l <= r)
    {
        int mid = l + (r - l) / 2;
        if (ar[mid] <= mi)
        {
            ans = mid + 1;
            l = mid + 1;
        }
        else
            r = mid - 1;
    }
    return ans;
}
int Solution::findMedian(vector<vector<int>> &A)
{
    int l = 1e9, r = -1e9;
    for (auto it : A)
    {
        l = min(l, it[0]);
        r = max(r, it.back());
    }
    int n = A.size(), m = A[0].size(), f = (n * m) / 2;
    while (l <= r)
    {
        int mid = l + (r - l) / 2;
        int c = 0;
        for (auto i : A)
            c += solveupper(i, mid);
        if (c <= f)
            l = mid + 1;
        else
            r = mid - 1;
    }
    return l;
}
