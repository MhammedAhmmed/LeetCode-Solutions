class Solution {
public:
    int snakesAndLadders(vector<vector<int>>& board) {
        int n = board.size();
        int boardLen = n * n;

        vector<bool> vis(boardLen + 1, false);
        vis[1] = true;

        queue<int> q;
        q.push(1);

        int dice = 0;
        while (!q.empty()) {
            int len = q.size();

            while (len--) {
                int pos = q.front();
                q.pop();

                if (pos == boardLen) {
                    return dice;
                }

                for (int i = 1; i <= 6; i++) {
                    pos++;

                    if (pos <= boardLen) {
                        int row = n - ((pos - 1) / n) - 1;
                        int col = (pos - 1) % n;

                        if (((n - 1) - row) & 1) {
                            col = n - col - 1;
                        }

                        if (vis[pos]) {
                            continue;
                        }

                        vis[pos] = 1;

                        if (board[row][col] == -1) {
                            q.push(pos);
                        } else {
                            q.push(board[row][col]);
                        }
                    }
                }
            }

            dice++;
        }

        return -1;
    }
};