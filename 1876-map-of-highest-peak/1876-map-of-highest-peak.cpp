class Solution {
public:
    vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {

        int m = isWater.size();
        int n = isWater[0].size();

        vector<vector<int>> height(m, vector<int>(n, -1));
        queue<pair<pair<int, int>, int>> q;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (isWater[i][j]) {
                    q.push({{i, j}, 0});
                    height[i][j] = 0;
                }
            }
        }

        vector<int> X{1, -1, 0, 0};
        vector<int> Y{0, 0, 1, -1};
        while (!q.empty()) {
            int i = q.front().first.first;
            int j = q.front().first.second;
            int h = q.front().second;

            q.pop();

            for (int k = 0; k < 4; k++) {
                int x = i + X[k];
                int y = j + Y[k];

                if (x >= 0 && x < m && y >= 0 && y < n && height[x][y] == -1) {
                    height[x][y] = h + 1;
                    q.push({{x, y}, h + 1});
                }
            }
        }

        return height;
    }
};