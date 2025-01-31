class Solution {
public:
    void dfs(int i, int j, int n, vector<vector<int>>& grid, int num) {
        if (i < 0 || i >= n || j < 0 || j >= n || grid[i][j] == num ||
            grid[i][j] == 0) {
            return;
        }

        grid[i][j] = num;

        dfs(i + 1, j, n, grid, num);
        dfs(i - 1, j, n, grid, num);
        dfs(i, j + 1, n, grid, num);
        dfs(i, j - 1, n, grid, num);
    }
    int largestIsland(vector<vector<int>>& grid) {

        int n = grid.size();
        int num = 2;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) {
                    dfs(i, j, n, grid, num);
                    num++;
                }
            }
        }

        unordered_map<int, int> mp;
        int res = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j]) {
                    mp[grid[i][j]]++;
                    res = max(res, mp[grid[i][j]]);
                }
            }
        }

        vector<int> X{1, -1, 0, 0};
        vector<int> Y{0, 0, 1, -1};

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 0) {
                    set<int> s;
                    for (int k = 0; k < 4; k++) {
                        if (i + X[k] >= 0 && i + X[k] < n && j + Y[k] >= 0 &&
                            j + Y[k] < n) {
                            s.insert(grid[i + X[k]][j + Y[k]]);
                        }
                    }

                    int sum = 1;
                    for (auto pos : s) {
                        sum += mp[pos];
                    }

                    res = max(res, sum);
                }
            }
        }

        return res;
    }
};