class Solution
{
    int MOD = 1e9 + 7;

    int recur(int n, int k, int target)
    {
        if (target == 0)
        {
            return n == 0;
        }
        if (target < 0 || n <= 0)
        {
            return 0;
        }

        long long ans = 0;
        for (int i = 1; i <= k; i++)
        {
            ans = (ans + recur(n - 1, k, target - i)) % MOD;
        }
        return ans % MOD;
    }

    vector<vector<int>> mem;
    int memo(int n, int k, int target)
    {
        if (target == 0)
        {
            return n == 0;
        }
        if (target < 0 || n <= 0)
        {
            return 0;
        }
        if (mem[n][target] != -1)
            return mem[n][target];

        long long ans = 0;
        for (int i = 1; i <= k; i++)
        {
            ans = (ans + memo(n - 1, k, target - i)) % MOD;
        }
        mem[n][target] = ans % MOD;
        return mem[n][target];
    }

    int dp(int n, int k, int target)
    {
        mem = vector<vector<int>>(n + 1, vector<int>(target + 1, 0));
        mem[0][0] = 1;
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= target; j++)
            {
                for (int kk = 1; kk <= k; kk++)
                {
                    if (j - kk < 0)
                        continue;
                    mem[i][j] = (mem[i][j] + mem[i - 1][j - kk]) % MOD;
                }
            }
        }
        return mem[n][target];
    }

public:
    int numRollsToTarget(int n, int k, int target)
    {
        // return recur(n, k, target);

        // mem = vector<vector<int>> (n+1, vector<int> (target + 1, -1));
        // return memo(n, k, target);

        return dp(n, k, target);
    }
};