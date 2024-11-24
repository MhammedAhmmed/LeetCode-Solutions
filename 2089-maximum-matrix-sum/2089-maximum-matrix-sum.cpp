class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();

        int smallestNum = INT_MAX;
        int numNeg = 0;
        long long sum = 0;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (matrix[i][j] < 0) {
                    numNeg++;
                }
                smallestNum = min(smallestNum, abs(matrix[i][j]));

                sum += abs(matrix[i][j]);
            }
        }

        if ((numNeg & 1) == 1) {
            sum -= (2 * smallestNum);
        }

        return sum;
    }
};