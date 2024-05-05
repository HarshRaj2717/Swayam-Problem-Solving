class Solution {
    int recursion(string &text1, string &text2, int i = 0, int j = 0)
    {
        if (i >= text1.size() || j >= text2.size())
            return 0;
        if (text1[i] == text2[j])
        {
            return 1 + recursion(text1, text2, i + 1, j + 1);
        }
        else
        {
            return max(recursion(text1, text2, i, j + 1), recursion(text1, text2, i + 1, j));
        }
        return 0;
    }

    vector<vector<int>> mem;
    int memoization(string &text1, string &text2, int i = 0, int j = 0)
    {
        if (i >= text1.size() || j >= text2.size())
            return 0;
        if (mem[i][j] != -1)
            return mem[i][j];
        if (text1[i] == text2[j])
        {
            mem[i][j] = 1 + memoization(text1, text2, i + 1, j + 1);
        }
        else
        {
            mem[i][j] = max(memoization(text1, text2, i, j + 1), memoization(text1, text2, i + 1, j));
        }
        return mem[i][j];
    }

    int tabulation(string &text1, string &text2)
    {
        // mem[i][j] == LCS till now (at **size** i from text1 and **size** j from text2)
        // botton-up
        for (int i = 1; i <= text1.size(); i++)
        {
            for (int j = 1; j <= text2.size(); j++)
            {
                if (text1[i-1] == text2[j-1])
                    mem[i][j] = 1 + mem[i-1][j-1];
                else
                    mem[i][j] = max(mem[i-1][j], mem[i][j-1]);
            }
        }
        return mem[text1.size()][text2.size()];
    }

public:
    int longestCommonSubsequence(string text1, string text2) {
        // return recursion(text1, text2);

        // mem = vector<vector<int>> (text1.size(), vector<int> (text2.size(), -1));
        // return memoization(text1, text2);

        mem = vector<vector<int>> (text1.size() + 1, vector<int> (text2.size() + 1, 0));
        return tabulation(text1, text2);
    }
};