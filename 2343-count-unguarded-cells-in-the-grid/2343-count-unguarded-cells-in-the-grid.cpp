class Solution {
    void protect(vector<vector<int>>& board, int m, int n, vector<int> guard) {
        int row = guard[0];
        int col = guard[1];

        int p = 1;
        while (row - p >= 0 &&
               (board[row - p][col] == 0 || board[row - p][col] == 2)) {
            board[row - p][col] = 2;
            p++;
        }

        p = 1;
        while (col + p < n &&
               (board[row][col + p] == 0 || board[row][col + p] == 2)) {
            board[row][col + p] = 2;
            p++;
        }

        p = 1;
        while (row + p < m &&
               (board[row + p][col] == 0 || board[row + p][col] == 2)) {
            board[row + p][col] = 2;
            p++;
        }

        p = 1;
        while (col - p >= 0 &&
               (board[row][col - p] == 0 || board[row][col - p] == 2)) {
            board[row][col - p] = 2;
            p++;
        }
    }

public:
    int countUnguarded(int m, int n, vector<vector<int>>& guards,
                       vector<vector<int>>& walls) {
        vector<vector<int>> board(m, vector<int>(n, 0));

        for (auto wall : walls) {
            board[wall[0]][wall[1]] = 3;
        }
        for (auto guard : guards) {
            board[guard[0]][guard[1]] = 1;
        }

        for (auto guard : guards) {
            protect(board, m, n, guard);
        }

        int res = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (board[i][j] == 0)
                    res++;
            }
        }

        return res;
    }
};