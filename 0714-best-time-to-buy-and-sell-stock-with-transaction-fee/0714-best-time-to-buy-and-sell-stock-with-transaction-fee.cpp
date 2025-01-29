class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int n = prices.size();

        vector<int> dp(n);
        dp[0] = 0;

        int maxTellNow = 0 - prices[0] - fee + dp[0], profit;
        for (int i = 1; i < n; i++) {
            dp[i] = max(prices[i] + maxTellNow, dp[i - 1]);
            maxTellNow = max(maxTellNow, 0 - prices[i] - fee + dp[i]);
        }

        return dp[n - 1];
    }
};