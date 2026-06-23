class Solution {
public:
    int minimumCost(vector<int>& cost) {
        sort(cost.begin(), cost.end());

        int n = cost.size();
        int res = 0;
        for(int i = n - 1; i >= 0; i--){
            res += cost[i];
            if(i - 1 >= 0){
                res += cost[i - 1];
            }
            i -= 2;
        }
        return res;
    }
};