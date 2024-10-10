class Solution {
    int whileIncreasing(vector<int>& prices, int n, int index) {

        index++;
        while (index < n && prices[index] >= prices[index - 1]) {
            index++;
        }

        return index - 1;
    }

public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();

        int res = 0;
        for (int i = 0; i < n; i++) {
            int buy = prices[i];
            int sellDay = whileIncreasing(prices, n, i);
            res += (prices[sellDay] - buy);

            i = sellDay;
        }
        return res;
    }
};