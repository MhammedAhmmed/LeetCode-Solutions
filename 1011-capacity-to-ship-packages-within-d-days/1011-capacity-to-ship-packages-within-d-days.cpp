class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int n = weights.size();
        
        int sum = 0;
        for (int x : weights)
            sum += x;

        int l = *max_element(weights.begin(), weights.end()), r = sum, res = sum;

        while (l <= r) {
            int mid = (l + r) / 2;

            int dayNum = 1, temp = 0;
            for (int i = 0; i < n; i++) {
                if (temp + weights[i] > mid) {
                    dayNum++;
                    temp = 0;
                }
                temp += weights[i];
            }
            if (dayNum <= days) {
                res = min(res, mid);
                r = mid - 1;
            }
            else
                l = mid + 1;
        }

        return res;
    }
};