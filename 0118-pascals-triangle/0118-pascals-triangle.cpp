class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> res(numRows);
        res[0] = {1};

        for (int i = 1; i < numRows; i++) {
            vector<int> row(i + 1);

            row[0] = row[i] = 1;

            for (int j = 1; j < i; j++) {
                row[j] = res[i - 1][j - 1] + res[i - 1][j];
            }

            res[i] = row;
        }

        return res;
    }
};