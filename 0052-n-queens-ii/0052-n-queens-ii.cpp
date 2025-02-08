class Solution {
    bool validCombination(vector<int>& pos, int n) {

        int row, col;
        for (int i = 0; i < n - 1; i++) {
            row = pos[i];
            col = i;

            while (row + 1 < n && col + 1 < n) {
                if (pos[col + 1] == row + 1) {
                    return false;
                }
                row++;
                col++;
            }

            row = pos[i];
            col = i;

            while (row - 1 >= 0 && col + 1 < n) {
                if (pos[col + 1] == row - 1) {
                    return false;
                }
                row--;
                col++;
            }
        }

        return true;
    }

    int res = 0;
    void solve(vector<bool>& rowTake, vector<int>& pos, int index, int n) {
        if (index == n) {
            if (validCombination(pos, n)) {
                res++;
            }
            return;
        }

        for (int i = 0; i < n; i++) {
            if (!rowTake[i]) {
                rowTake[i] = 1;
                pos[index] = i;

                solve(rowTake, pos, index + 1, n);

                rowTake[i] = 0;
            }
        }
    }

public:
    int totalNQueens(int n) {
        vector<bool> rowTake(n, false);
        vector<int> pos(n);

        solve(rowTake, pos, 0, n);

        return res;
    }
};