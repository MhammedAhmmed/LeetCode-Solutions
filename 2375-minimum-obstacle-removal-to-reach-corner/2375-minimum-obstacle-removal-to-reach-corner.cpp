class Solution {
    bool validPos(int i, int j, int m, int n) {
        return i >= 0 && i < m && j >= 0 && j < n;
    }

public:
    int minimumObstacles(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();

        vector<vector<int>> dis(m, vector<int>(n, INT_MAX));

        priority_queue<pair<int, pair<int, int>>,
                       vector<pair<int, pair<int, int>>>,
                       greater<pair<int, pair<int, int>>>>
            pq;

        dis[0][0] = 0;

        pq.push({0, {0, 0}});

        vector<int> X{1, -1, 0, 0};
        vector<int> Y{0, 0, 1, -1};

        while (!pq.empty()) {
            int w = pq.top().first;
            pair<int, int> pos = pq.top().second;

            pq.pop();

            for (int i = 0; i < 4; i++) {
                int x = pos.first + X[i];
                int y = pos.second + Y[i];

                if (validPos(x, y, m, n)) {
                    if (dis[pos.first][pos.second] + grid[x][y] < dis[x][y]) {
                        dis[x][y] = dis[pos.first][pos.second] + grid[x][y];

                        pq.push({dis[x][y], {x, y}});
                    }
                }
            }
        }

        return dis[m - 1][n - 1];
    }
};