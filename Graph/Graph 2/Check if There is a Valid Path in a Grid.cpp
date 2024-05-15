class Solution {
    vector<vector<vector<int>>> streets = {
        {{0, -1}, {0, 1}},
        {{-1, 0}, {1, 0}},
        {{0, -1}, {1, 0}},
        {{1, 0}, {0, 1}},
        {{0, -1}, {-1, 0}},
        {{-1, 0}, {0, 1}},
    };

    pair<int, int> whereTo(int pi, int pj, int i, int j, int curStreet) {
        curStreet--;
        if (pi == -2 && pj == -2)
            return {streets[curStreet][1][0], streets[curStreet][1][1]};

        if (pi - i == streets[curStreet][0][0] && pj - j == streets[curStreet][0][1])
            return {i + streets[curStreet][1][0], j + streets[curStreet][1][1]};

        if (pi - i == streets[curStreet][1][0] && pj - j == streets[curStreet][1][1])
            return {i + streets[curStreet][0][0], j + streets[curStreet][0][1]};

        return {-1, -1};
    }

public:
    bool hasValidPath(vector<vector<int>>& grid, int i = 0, int j = 0, int pi = -2, int pj = -2) {
        if (pi == grid.size() - 1 && pj == grid[0].size() - 1 && i != -1 && j != -1)
            return true;
        if (i < 0 || j < 0 || i >= grid.size() || j >= grid[0].size())
            return false;
        if (grid[i][j] == 0)
            return false;

        int save = grid[i][j];
        grid[i][j] = 0;

        pair<int, int> dir;

        if (pi == -2 && pj == -2 && save == 4) {
            dir = whereTo(1, 0, i, j, save);
            if (hasValidPath(grid, dir.first, dir.second, i, j))
                return true;

            dir = whereTo(0, 1, i, j, save);
            if (hasValidPath(grid, dir.first, dir.second, i, j))
                return true;

            return false;
        }

        dir = whereTo(pi, pj, i, j, save);
        return hasValidPath(grid, dir.first, dir.second, i, j);
    }
};