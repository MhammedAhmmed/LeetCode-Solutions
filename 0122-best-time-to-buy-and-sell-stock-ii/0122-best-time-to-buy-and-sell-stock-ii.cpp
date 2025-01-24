class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();

        int res = 0;
        for(int i = 0; i < n - 1;i++){
            if(prices[i+1] > prices[i]){
                res += prices[i+1] - prices[i];
            }
        }
        
        return res;
    }
};