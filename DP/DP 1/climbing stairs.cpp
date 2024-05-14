class Solution
{
    int recursive(int n)
    {
        if (n < 0)
            return 0;
        if (n == 0)
            return 1;

        return recursive(n - 1) + recursive(n - 2);
    }

    vector<int> mem;
    int memoization(int n)
    {
        if (n < 0)
            return 0;
        if (n == 0)
            return 1;
        if (mem[n - 1] != -1)
            return mem[n - 1];

        mem[n - 1] = memoization(n - 1) + memoization(n - 2);
        return mem[n - 1];
    }

    int dp(int n)
    {
        mem = vector<int>(n + 2);
        // increasing 1 at each index so that result of n == -1 can also be stored in `mem`
        mem[-1 + 1] = 0;
        mem[0 + 1] = 1;
        // mem[i] => number of ways to reach 0 from `i`
        for (int i = 1; i <= n; i++)
        {
            mem[i + 1] = mem[i] + mem[i - 1];
        }

        return mem[n + 1];
    }

public:
    int climbStairs(int n)
    {
        // return recursive(n);

        // mem = vector<int> (n, -1);
        // return memoization(n);

        return dp(n);
    }
};