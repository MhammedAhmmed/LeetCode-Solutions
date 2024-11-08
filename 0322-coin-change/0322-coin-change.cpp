class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount + 1, -1);

        dp[0] = 0;
        int n = coins.size();

        for (int i = 1; i <= amount; i++) {
            for (int j = 0; j < n; j++) {
                if (i - coins[j] >= 0) {
                    if (dp[i - coins[j]] != -1) {
                        if (dp[i] == -1) {
                            dp[i] = 1 + dp[i - coins[j]];
                        } else {
                            dp[i] = min(dp[i], 1 + dp[i - coins[j]]);
                        }
                    }
                }
            }
        }

        return dp[amount];
    }
};