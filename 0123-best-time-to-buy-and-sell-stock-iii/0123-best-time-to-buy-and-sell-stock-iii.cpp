class Solution {
public:
    int maxProfit(vector<int>& prices) {
        
        int n = prices.size();
        vector<int> maxLeft(n), maxRight(n);

        maxLeft[0] = 0;
        int minNum = prices[0];
        for (int i = 1; i < n; i++) {
            minNum = min(minNum, prices[i]);
            maxLeft[i] = max(maxLeft[i - 1], prices[i] - minNum);
        }

        maxRight[n - 1] = 0;
        int maxNum = prices[n - 1];
        for (int i = n - 2; i >= 0; i--) {
            maxNum = max(maxNum, prices[i]);
            maxRight[i] = max(maxRight[i + 1], maxNum - prices[i]);
        }

        int profit = 0;
        for (int i = 0; i < n; i++) {
            profit = max(profit, maxLeft[i] + maxRight[i]);
        }

        return profit;
    }
};