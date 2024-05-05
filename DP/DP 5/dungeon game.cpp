class Solution {
public:
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        int m = dungeon.size() - 1;
        int n = dungeon[0].size() - 1;
        

        dungeon[m][n] = dungeon[m][n] > 0 ? 1 : abs(dungeon[m][n]) + 1;

        for (int j = n - 1; j >= 0; j--)
        {
            if (dungeon[m][j] > 0)
                dungeon[m][j] = max(1, dungeon[m][j+1] - dungeon[m][j]);
            else
                dungeon[m][j] = abs(dungeon[m][j]) + dungeon[m][j + 1];
        }

        for (int i = m - 1; i >= 0; i--)
        {
            if (dungeon[i][n] > 0)
                dungeon[i][n] = max(1, dungeon[i + 1][n] - dungeon[i][n]);
            else
                dungeon[i][n] = abs(dungeon[i][n]) + dungeon[i + 1][n];
        }

        for (int i = m - 1; i >= 0; i--)
        {
            for (int j = n - 1; j >= 0; j--)
            {
                if (dungeon[i][j] > 0)
                    dungeon[i][j] = max(1, min(dungeon[i + 1][j], dungeon[i][j + 1]) - dungeon[i][j]);
                else
                    dungeon[i][j] = abs(dungeon[i][j]) + min(dungeon[i + 1][j], dungeon[i][j + 1]);
            }
        }

        return dungeon[0][0];
    }
};