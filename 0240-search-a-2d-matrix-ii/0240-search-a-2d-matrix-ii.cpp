class Solution {
public:
    bool search(vector<vector<int>>& matrix, int target, int fr, int sr, int fc,
                int sc) {
        if (fr > sr || fc > sc) {
            return false;
        }

        int midr = (fr + sr) / 2;
        int midc = (fc + sc) / 2;

        if (matrix[midr][midc] == target) {
            return true;
        }
        if (matrix[midr][midc] > target) {
            return search(matrix, target, fr, sr, fc, midc - 1) ||
                   search(matrix, target, fr, midr - 1, fc, sc);
        }
        return search(matrix, target, fr, sr, midc + 1, sc) ||
               search(matrix, target, midr + 1, sr, fc, sc);
    }

    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int fr = 0, sr = matrix.size() - 1;
        int fc = 0, sc = matrix[0].size() - 1;

        return search(matrix, target, fr, sr, fc, sc);
    }
};