class Solution {
public:
    int maxCount(vector<int>& banned, int n, int maxSum) {
        vector<bool> take(n + 1, false);

        int len = banned.size();
        for (int i = 0; i < len; i++) {
            if (banned[i] <= n) {
                take[banned[i]] = true;
            }
        }

        int sum = 0, res = 0;

        for (int i = 1; i <= n; i++) {
            if (!take[i]) {
                if (sum + i <= maxSum) {
                    sum += i;
                    res++;
                } else {
                    break;
                }
            }
        }

        return res;
    }
};