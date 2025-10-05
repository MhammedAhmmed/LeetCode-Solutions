class Solution {
    void bfs(int m, int n, queue<pair<int, int>>& q, vector<vector<bool>>& vis,
             vector<vector<int>>& pacificAndAtalantic,
             vector<vector<int>>& heights) {

        vector<int> X{1, -1, 0, 0};
        vector<int> Y{0, 0, 1, -1};
        while (!q.empty()) {
            int i = q.front().first;
            int j = q.front().second;
            q.pop();

            pacificAndAtalantic[i][j]++;

            for (int k = 0; k < 4; k++) {
                int x = i + X[k];
                int y = j + Y[k];

                if (x >= 0 && x < m && y >= 0 && y < n && !vis[x][y] &&
                    heights[x][y] >= heights[i][j]) {
                    vis[x][y] = true;
                    q.push({x, y});
                }
            }
        }
    }

public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {

        int m = heights.size();
        int n = heights[0].size();

        queue<pair<int, int>> q;
        vector<vector<bool>> vis(m, vector<bool>(n, false));
        for (int i = 0; i < m; i++) {
            q.push({i, n - 1});
            vis[i][n - 1] = true;
        }
        for (int i = 0; i < n - 1; i++) {
            q.push({m - 1, i});
            vis[m - 1][i] = true;
        }

        vector<vector<int>> pacificAndAtalantic(m, vector<int>(n, 0));

        bfs(m, n, q, vis, pacificAndAtalantic, heights);
        vis.assign(m, vector<bool>(n, false));

        for (int i = 0; i < m; i++) {
            q.push({i, 0});
            vis[i][0] = true;
        }
        for (int i = 1; i < n; i++) {
            q.push({0, i});
            vis[0][i] = true;
        }
        bfs(m, n, q, vis, pacificAndAtalantic, heights);

        vector<vector<int>> res;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (pacificAndAtalantic[i][j] == 2) {
                    res.push_back({i, j});
                }
            }
        }

        return res;
    }
};