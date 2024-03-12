#include <bits/stdc++.h>

using namespace std;

bool check(int mid, vector<int> &nums, int m)
{
    int cnt = 0;
    for (auto it : nums)
        if (it > mid)
            cnt += ((it / mid) - (it % mid == 0));
    return cnt <= m;
}

int solver(vector<int> &nums, int m)
{
    int lo = 1;
    int hi = 1;
    for (auto it : nums)
        hi = max(hi, it);
    while (lo < hi)
    {
        int mid = (hi + lo) / 2;
        if (check(mid, nums, m))
        {
            hi = mid;
        }
        else
        {
            lo = mid + 1;
        }
    }
    return hi;
}

int main()
{
    int n, m;
    cin >> n >> m;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    cout << solver(arr, m) << endl;
    return 0;
}