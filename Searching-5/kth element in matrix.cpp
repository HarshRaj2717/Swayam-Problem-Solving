
int kthSmallest(int mat[MAX][MAX], int n, int k)
{
  // Your code here
  int l = 0, r = 1e9;
  k--;
  while (l <= r)
  {
    int m = l + (r - l) / 2, c = 0;
    for (int i = 0; i < n; i++)
      c += (upper_bound(mat[i], mat[i] + n, m) - mat[i]);
    if (c <= k)
      l = m + 1;
    else
      r = m - 1;
  }
  return l;
}
