class Solution {
public:
    int equalPairs(vector<vector<int>>& grid) {
        unordered_map<string, int> rowFreq, colFreq;

        int n = grid.size();

        for (int i = 0; i < n; i++) {
            string temp = "";
            for (int j = 0; j < n; j++) {
                temp += to_string(grid[i][j]);
                temp += ",";
            }
            rowFreq[temp]++;
        }

        for (int i = 0; i < n; i++) {
            string temp = "";
            for (int j = 0; j < n; j++) {
                temp += to_string(grid[j][i]);
                temp += ",";
            }
            colFreq[temp]++;
        }

        int res = 0;

        for (auto entry : rowFreq) {
            res += (entry.second * colFreq[entry.first]);
        }

        return res;
    }
};