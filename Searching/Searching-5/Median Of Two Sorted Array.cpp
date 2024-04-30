class Solution
{
public:
    double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2)
    {
        int n = nums1.size(), m = nums2.size();
        if (n > m)
            return findMedianSortedArrays(nums2, nums1);
        int l = 0, r = n;
        int mi = (n + m + 1) / 2;
        while (l <= r)
        {
            int mid = l + (r - l) / 2;
            int m1 = mi - mid;
            int c = (mid >= n) ? INT_MAX : nums1[mid];
            int d = (m1 >= m) ? INT_MAX : nums2[m1];
            int a = INT_MIN, b = INT_MIN;
            if (mid > 0)
                a = nums1[mid - 1];
            if (m1 > 0)
                b = nums2[m1 - 1];
            if (a <= d && b <= c)
            {
                if ((n + m) & 1)
                    return (double)max(a, b);
                else
                    return (double)(max(a, b) + min(c, d)) / 2.0;
            }
            if (a > d)
                r = mid - 1;
            else
                l = mid + 1;
        }
        return -1;
    }
};