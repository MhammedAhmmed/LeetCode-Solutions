class Solution {
    bool allOnes(vector<vector<int>>& matrix, int row, int col, int k) {
        for (int i = row; i <= row + k; i++) {
            for (int j = col; j <= col + k; j++) {
                if (!matrix[i][j])
                    return false;
            }
        }

        return true;
    }

public:
    int countSquares(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();

        int maxSquare = min(n, m);
        int res = 0;
        for (int k = 0; k < maxSquare; k++) {
            for (int i = 0; i < m - k; i++) {
                for (int j = 0; j < n - k; j++) {
                    if (allOnes(matrix, i, j, k))
                        res++;
                }
            }
        }

        return res;
    }
};