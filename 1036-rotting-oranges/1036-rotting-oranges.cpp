class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();

        queue<pair<int, int>> q;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 2) {
                    q.push({i, j});
                }
            }
        }

        int minutes = 0;

        vector<int> X{1, -1, 0, 0};
        vector<int> Y{0, 0, 1, -1};
        while (!q.empty()) {
            queue<pair<int, int>> temp;

            while (!q.empty()) {
                pair<int, int> pos = q.front();
                q.pop();

                for (int i = 0; i < 4; i++) {
                    int x = pos.first + X[i];
                    int y = pos.second + Y[i];

                    if (x >= 0 && x < m && y >= 0 && y < n && grid[x][y] == 1) {
                        temp.push({x, y});
                        grid[x][y] = 2;
                    }
                }
            }

            if (!temp.empty()) {
                minutes++;
            }

            q = temp;
        }

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) {
                    return -1;
                }
            }
        }
        return minutes;
    }
};