class Solution {
public:
    int maxEqualRowsAfterFlips(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();

        unordered_map<string, int> freq;

        for (int i = 0; i < m; i++) {
            string s0 = "", s1 = "";
            for (int j = 0; j < n; j++) {
                if (matrix[i][j] == 0) {
                    s0 = s0 + to_string(j);
                } else {
                    s1 = s1 + to_string(j);
                }
            }

            freq[s0]++;
            freq[s1]++;
        }

        int maxRows = 0;

        for (auto entry : freq) {
            maxRows = max(maxRows, entry.second);
        }

        return maxRows;
    }
};