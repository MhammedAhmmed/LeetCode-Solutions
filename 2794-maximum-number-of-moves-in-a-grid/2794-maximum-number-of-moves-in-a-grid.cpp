class Solution {
public:
    int maxPath(vector<vector<int>>& grid, vector<vector<int>>& dp, int i,
                int j, int prev) {
        if (i < 0 || i >= grid.size() || j < 0 || j >= grid[0].size() ||
            grid[i][j] <= prev)
            return 0;

        if (dp[i][j] != -1)
            return dp[i][j];

        int depth1 = maxPath(grid, dp, i - 1, j + 1, grid[i][j]);
        int depth2 = maxPath(grid, dp, i, j + 1, grid[i][j]);
        int depth3 = maxPath(grid, dp, i + 1, j + 1, grid[i][j]);

        return dp[i][j] = max(depth1, max(depth2, depth3)) + 1;
    }

    int maxMoves(vector<vector<int>> grid) {
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<int>> dp(m, vector<int>(n, -1));

        int res = 1;

        for (int i = 0; i < m; i++) {
            res = max(res, maxPath(grid, dp, i, 0, -1));
        }

        return res - 1;
    }
};