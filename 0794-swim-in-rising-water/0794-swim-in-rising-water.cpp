class Solution {
    bool reach = false;
    void dfs(vector<vector<int>>& grid, vector<vector<bool>>& vis, int i, int j,
             int n, int t) {
        if (i < 0 || i >= n || j < 0 || j >= n || vis[i][j] || grid[i][j] > t) {
            return;
        }

        vis[i][j] = true;

        if (i == n - 1 && j == n - 1) {
            reach = true;
            return;
        }

        dfs(grid, vis, i + 1, j, n, t);
        dfs(grid, vis, i - 1, j, n, t);
        dfs(grid, vis, i, j + 1, n, t);
        dfs(grid, vis, i, j - 1, n, t);
    }

public:
    int swimInWater(vector<vector<int>>& grid) {

        int n = grid.size();
        vector<vector<bool>> vis;
        int t = 0;
        while (!reach) {
            vis.assign(n, vector<bool>(n, false));
            dfs(grid, vis, 0, 0, n, t);
            if (reach) {
                return t;
            }

            t++;
        }
        return t;
    }
};