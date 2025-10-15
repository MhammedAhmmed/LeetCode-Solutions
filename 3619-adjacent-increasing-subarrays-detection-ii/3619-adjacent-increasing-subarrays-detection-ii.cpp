class Solution {
public:
    int maxIncreasingSubarrays(vector<int>& nums) {

        int n = nums.size();
        vector<int> maxInc(n, 1);

        for (int i = n - 2; i >= 0; i--) {
            if (nums[i] < nums[i + 1]) {
                maxInc[i] = maxInc[i + 1] + 1;
            }
        }

        int k = 0;
        for (int i = 0; i < n; i++) {
            k = max(k, maxInc[i] / 2);

            if (i + maxInc[i] < n) {
                k = max(k, min(maxInc[i], maxInc[i + maxInc[i]]));
            }
        }
        return k;
    }
};