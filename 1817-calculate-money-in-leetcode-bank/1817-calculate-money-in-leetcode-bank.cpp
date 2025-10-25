class Solution {
public:
    int totalMoney(int n) {
        
        int res = 0;
        int round = -1;
        for(int i = 1; i <= n; i += 7){
            int x = min(7, n - i + 1);
            round++;
            for(int j = 1; j <= x; j++){
                res += (j + round);
            }
        }
        return res;
    }
};