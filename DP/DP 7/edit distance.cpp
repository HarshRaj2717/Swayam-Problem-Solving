class Solution {
    int recur(string &word1, string &word2, int i = 0, int j = 0)
    {
        if (j == word2.size())
            return word1.size() - i;
        if (i == word1.size())
            return word2.size() - j;
        if (word1[i] == word2[j])
            return recur(word1, word2, i + 1, j + 1);

        // insert
        int a = recur(word1, word2, i, j + 1);
        // delete
        int b = recur(word1, word2, i + 1, j);
        // replace
        int c = recur(word1, word2, i + 1, j + 1);

        return 1 + min({a, b, c});
    }

    vector<vector<int>> mem;
    int memo(string &word1, string &word2, int i = 0, int j = 0)
    {
        if (j == word2.size())
            return word1.size() - i;
        if (i == word1.size())
            return word2.size() - j;
        if (mem[i][j] != -1)
            return mem[i][j];
        if (word1[i] == word2[j])
            return memo(word1, word2, i + 1, j + 1);

        // insert
        int a = memo(word1, word2, i, j + 1);
        // delete
        int b = memo(word1, word2, i + 1, j);
        // replace
        int c = memo(word1, word2, i + 1, j + 1);

        mem[i][j] = 1 + min({a, b, c});
        return mem[i][j];
    }

    int tabulation(string &word1, string &word2)
    {
        vector<vector<int>> dp(word1.size() + 1, vector<int> (word2.size() + 1, 0));

        dp[0][0] = 0;

        for (int i = 1; i <= word1.size(); i++)
        {
            dp[i][0] = i;
        }
        for (int i = 1; i <= word2.size(); i++)
        {
            dp[0][i] = i;
        }

        for (int i = 1; i <= word1.size(); i++)
        {
            for (int j = 1; j <= word2.size(); j++)
            {
                if (word1[i - 1] == word2[j - 1])
                {
                    dp[i][j] = dp[i-1][j-1];
                    continue;
                }
                dp[i][j] = 1 + min({dp[i-1][j-1], dp[i-1][j], dp[i][j-1]});
            }
        }

        return dp[word1.size()][word2.size()];
    }

    int tabulationOptimized(string &word1, string &word2)
    {
        vector<int> dp(word2.size() + 1);
        for (int i = 0; i <= word2.size(); i++)
        {
            dp[i] = i;
        }

        for (int i = 1; i <= word1.size(); i++)
        {
            int prev = dp[0];
            dp[0] = i;
            for (int j = 1; j <= word2.size(); j++)
            {
                if (word1[i - 1] == word2[j - 1])
                {
                    swap(dp[j], prev);
                    continue;
                }
                int cur = 1 + min({prev, dp[j], dp[j-1]});
                prev = dp[j];
                dp[j] = cur;
            }
        }

        return dp[word2.size()];
    }
public:
    int minDistance(string word1, string word2) {
        // return recur(word1, word2);

        // mem = vector<vector<int>> (word1.size(), vector<int> (word2.size(), -1));
        // return memo(word1, word2);

        // return tabulation(word1, word2);

        return tabulationOptimized(word1, word2);
    }
};