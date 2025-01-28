class Solution {
public:
    int collectFish(int i, int j, int m, int n, vector<vector<int>>& grid) {
        if (i < 0 || i >= m || j < 0 || j >= n || grid[i][j] == 0) {
            return 0;
        }

        int sum = grid[i][j];
        grid[i][j] = 0;

        sum += collectFish(i + 1, j, m, n, grid);
        sum += collectFish(i - 1, j, m, n, grid);
        sum += collectFish(i, j + 1, m, n, grid);
        sum += collectFish(i, j - 1, m, n, grid);

        return sum;
    }
    int findMaxFish(vector<vector<int>>& grid) {

        int m = grid.size(), n = grid[0].size();

        int maxFish = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j]) {
                    maxFish = max(maxFish, collectFish(i, j, m, n, grid));
                }
            }
        }

        return maxFish;
    }
};