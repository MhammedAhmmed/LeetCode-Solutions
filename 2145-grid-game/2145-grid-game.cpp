class Solution {
    public:
        long long gridGame(vector<vector<int>>& grid) {
            int n = grid[0].size();
            vector<vector<long long>>prefix(2, vector<long long>(n));

            for (int i = 0; i < n; i++) {
                prefix[0][i] = grid[0][i];
                prefix[1][i] = grid[1][i];
            }
            for (int i = 1; i < n; i++) {
                prefix[0][i] += prefix[0][i - 1];
                prefix[1][i] += prefix[1][i - 1];
            }

            long long res = LONG_MAX;
            res = min(res, prefix[0][n - 1] - prefix[0][0]);
            for (int i = 1; i < n; i++) {
                res = min (res,(max(prefix[0][n - 1] - prefix[0][i], prefix[1][i - 1])));
            }


            return res;
        }
};