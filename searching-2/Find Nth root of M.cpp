class Solution
{
public:
	long long power(long long b, long long exp)
	{
		if (exp == 1)
			return b;
		if (exp & 1)
			return b * power(b, exp - 1);
		return power(1LL * b * b, exp / 2);
	}
	int NthRoot(int n, int m)
	{
		// Code here.
		if (m == 1)
			return m;
		int x = 9;
		x /= n;
		int q = 10;
		while (x--)
			q *= 10;
		long long l = 1, h = min(m, q), ans = -1, nn = n;
		while (l <= h)
		{
			long long mid = l + (h - l) / 2;
			long long p = power(mid, nn);
			// cout<<p<<" "<<mid<<endl;
			if (p <= m)
			{
				if (p == m)
					ans = mid;
				l = mid + 1;
			}
			else
				h = mid - 1;
		}
		return ans;
	}
};