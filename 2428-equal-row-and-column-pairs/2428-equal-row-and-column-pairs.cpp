class Solution {
public:
    int equalPairs(vector<vector<int>>& grid) {
        unordered_map<string, int> rowFreq;

        int n = grid.size();

        for (int i = 0; i < n; i++) {
            string temp = "";
            for (int j = 0; j < n; j++) {
                temp += to_string(grid[i][j]);
                temp += ",";
            }
            rowFreq[temp]++;
        }

        int res = 0;
        for (int i = 0; i < n; i++) {
            string temp = "";
            for (int j = 0; j < n; j++) {
                temp += to_string(grid[j][i]);
                temp += ",";
            }
            res += rowFreq[temp];
        }

        return res;
    }
};