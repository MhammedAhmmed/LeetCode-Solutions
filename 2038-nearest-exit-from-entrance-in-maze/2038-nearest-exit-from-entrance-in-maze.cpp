class Solution {
public:
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        int m = maze.size(), n = maze[0].size();

        queue<pair<int, int>> q;
        q.push({entrance[0], entrance[1]});

        int level = 0;
        vector<int> X{1, -1, 0, 0};
        vector<int> Y{0, 0, 1, -1};
        int x, y;
        while (!q.empty()) {
            queue<pair<int, int>> temp;

            while (!q.empty()) {
                pair<int, int> pos = q.front();
                q.pop();
                maze[pos.first][pos.second] = '+';

                x = pos.first, y = pos.second;
                if (x == 0 || x == m - 1 || y == 0 || y == n - 1) {
                    if (x != entrance[0] || y != entrance[1]) {
                        return level;
                    }
                }

                for (int i = 0; i < 4; i++) {
                    x = pos.first + X[i];
                    y = pos.second + Y[i];

                    if (x >= 0 && x < m && y >= 0 && y < n &&
                        maze[x][y] == '.') {
                        temp.push({x, y});
                        maze[x][y] = '+';
                    }
                }
            }

            level++;
            q = temp;
        }

        return -1;
    }
};