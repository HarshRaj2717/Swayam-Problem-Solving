#include <bits/stdc++.h>

using namespace std;

bool helper(int mid, vector<int> &bloomDay, int m, int k)
{
    int cnt = 0;
    int ans = 0;
    for (auto it : bloomDay)
    {
        if (it <= mid)
        {
            cnt++;
            if (cnt == k)
            {
                ans++;
                cnt = 0;
            }
        }
        else
        {
            cnt = 0;
        }
    }
    return ans >= (m);
}

int solver(vector<int> &bloomDay, int m, int k)
{
    if (m * 1ll * k > bloomDay.size())
        return -1;
    int start = 1;
    int end = 1e9;
    while (start < end)
    {
        int mid = (start + end) / 2;
        if (helper(mid, bloomDay, m, k))
        {
            end = mid;
        }
        else
        {
            start = mid + 1;
        }
    }
    return start;
}

int main()
{
    int n, m, k;
    cin >> n >> m >> k;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    cout << solver(arr, m, k) << endl;
    return 0;
}