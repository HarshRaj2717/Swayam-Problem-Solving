class Solution {
    long long recur(vector<vector<int>>& questions, int i = 0) {
        if (i >= questions.size())
            return 0;

        return max(recur(questions, i + 1), questions[i][0] + recur(questions, i + questions[i][1] + 1));
    }

    vector<long long> mem;
    long long memo(vector<vector<int>>& questions, int i = 0) {
        if (i >= questions.size())
            return 0;
        if (mem[i] != -1)
            return mem[i];

        mem[i] = max(memo(questions, i + 1), questions[i][0] + memo(questions, i + questions[i][1] + 1));
        return mem[i];
    }

    long long dp(vector<vector<int>>& questions) {
        mem = vector<long long> (questions.size(), 0);
        // dp[i] => max points that can be gained from i->n
        int i = questions.size() - 1;
        mem[i] = questions[i][0];
        i--;

        for (; i >= 0; i--) {
            mem[i] = max(mem[i + 1], questions[i][0] + (i + questions[i][1] + 1 < questions.size() ? mem[i + questions[i][1] + 1] : 0));
        }

        return mem[0];
    }
public:
    long long mostPoints(vector<vector<int>>& questions) {
        // return recur(questions);

        mem = vector<long long> (questions.size(), -1);
        return memo(questions);

        return dp(questions);
    }
};