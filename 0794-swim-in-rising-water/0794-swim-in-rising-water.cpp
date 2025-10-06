class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {

        int n = grid.size();
        vector<vector<bool>> vis(n, vector<bool>(n, false));

        priority_queue<pair<int, pair<int, int>>,
                       vector<pair<int, pair<int, int>>>,
                       greater<pair<int, pair<int, int>>>>
            pq;
        pq.push({grid[0][0], {0, 0}});

        vector<int> X{1, -1, 0, 0};
        vector<int> Y{0, 0, 1, -1};
        while (!pq.empty()) {
            int weight = pq.top().first;
            int x = pq.top().second.first;
            int y = pq.top().second.second;

            if (x == n - 1 && y == n - 1) {
                return weight;
            }

            pq.pop();
            if (vis[x][y]) {
                continue;
            }
            vis[x][y] = true;

            for (int k = 0; k < 4; k++) {
                int r = x + X[k];
                int c = y + Y[k];

                if (r >= 0 && r < n && c >= 0 && c < n && !vis[r][c]) {
                    pq.push({max(weight, grid[r][c]), {r, c}});
                }
            }
        }
        return 0;
    }
};