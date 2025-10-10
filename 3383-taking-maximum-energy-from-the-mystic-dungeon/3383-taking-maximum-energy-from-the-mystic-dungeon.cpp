class Solution {
public:
    int memo(int index, int n, vector<int>& dp, vector<int>& energy, int k) {
        if (index >= n) {
            return 0;
        }
        if (dp[index] != -1) {
            return dp[index];
        }

        return dp[index] = energy[index] + memo(index + k, n, dp, energy, k);
    }
    int maximumEnergy(vector<int>& energy, int k) {

        int n = energy.size();
        vector<int> dp(n, -1);
        int res = INT_MIN;
        for (int i = 0; i < n; i++) {
            res = max(res, memo(i, n, dp, energy, k));
        }

        return res;
    }
};