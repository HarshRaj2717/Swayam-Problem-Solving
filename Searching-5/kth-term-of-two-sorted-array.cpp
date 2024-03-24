#include <bits/stdc++.h>
int kthElement(vector<int> &arr1, vector<int> &arr2, int n, int m, int k)
{
    // Write your code here
    if (n > m)
        return kthElement(arr2, arr1, m, n, k);
    int l = max(0, k - m), r = min(k, n);
    while (l <= r)
    {
        int m1 = l + (r - l) / 2;
        int m2 = k - m1;
        int a = m1 < n ? arr1[m1] : INT_MAX;
        int b = m2 < m ? arr2[m2] : INT_MAX;
        int c = m1 > 0 ? arr1[m1 - 1] : INT_MIN;
        int d = m2 > 0 ? arr2[m2 - 1] : INT_MIN;
        if (d <= a && c <= b)
            return max(c, d);
        if (a > d)
            r = m1 - 1;
        else
            l = m1 + 1;
    }
    return -1;
}