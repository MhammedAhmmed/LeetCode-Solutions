class Solution {
public:
    int trapRainWater(vector<vector<int>>& heightMap) {

        priority_queue<pair<int, pair<int, int>>,
                       vector<pair<int, pair<int, int>>>,
                       greater<pair<int, pair<int, int>>>>
            pq;

        int m = heightMap.size();
        int n = heightMap[0].size();

        for (int i = 0; i < m; i++) {
            pq.push({heightMap[i][0], {i, 0}});
            pq.push({heightMap[i][n - 1], {i, n - 1}});
            heightMap[i][0] = heightMap[i][n - 1] = -1;
        }
        for (int i = 1; i < n - 1; i++) {
            pq.push({heightMap[0][i], {0, i}});
            pq.push({heightMap[m - 1][i], {m - 1, i}});
            heightMap[0][i] = heightMap[m - 1][i] = -1;
        }

        int res = 0;
        int max_h = -1;
        vector<int> X{1, -1, 0, 0};
        vector<int> Y{0, 0, 1, -1};
        while (!pq.empty()) {
            pair<int, pair<int, int>> top = pq.top();
            pq.pop();

            int h = top.first;
            int r = top.second.first, c = top.second.second;

            max_h = max(h, max_h);
            res += (max_h - h);

            for (int k = 0; k < 4; k++) {
                int x = r + X[k];
                int y = c + Y[k];

                if (x >= 0 && x < m && y >= 0 && y < n &&
                    heightMap[x][y] != -1) {
                    pq.push({heightMap[x][y], {x, y}});
                    heightMap[x][y] = -1;
                }
            }
        }

        return res;
    }
};