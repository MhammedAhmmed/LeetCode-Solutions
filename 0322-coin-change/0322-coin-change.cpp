class Solution {
    int coinChangeTD(vector<int>& coins, int n, vector<int>& dp, int amount) {
        if (dp[amount] != -2)
            return dp[amount];

        int res = amount;
        bool found = false;
        for (int i = 0; i < n; i++) {
            if (amount - coins[i] >= 0) {
                int remamnount = coinChangeTD(coins, n, dp, amount - coins[i]);
                if (remamnount != -1) {
                    found = true;
                    res = min(res, 1 + remamnount);
                }
            }
        }
        if (found) {
            return dp[amount] = res;
        }

        return dp[amount] = -1;
    }

public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount + 1, -2);
        dp[0] = 0;

        return coinChangeTD(coins, coins.size(), dp, amount);
    }
};