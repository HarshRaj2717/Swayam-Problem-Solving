#include <bits/stdc++.h>

using namespace std;

bool check(int mid, vector<int> &arr, int X)
{
    int left = 0;
    int sum = 0;
    for (int i = 0; i < mid; i++)
    {
        sum += arr[i];
    }
    if (sum > X)
        return false;
    for (int i = mid; i < arr.size(); i++)
    {
        sum += arr[i];
        sum -= arr[left++];
        if (sum > X)
            return false;
    }
    return true;
}

int solver(vector<int> &arr, int X)
{
    int lo = 0;
    int hi = arr.size();
    while (lo < hi)
    {
        int mid = (lo + hi) / 2;
        if (check(mid, arr, X))
        {
            lo = mid + 1;
        }
        else
        {
            hi = mid - 1;
        }
    }
    if (check(lo, arr, X))
        return lo;
    else
        return lo - 1;
}

int main()
{
    int n, x;
    cin >> n >> x;
    vector<int> nums(n);
    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];
    }
    cout << solver(nums, x) << endl;
    return 0;
}