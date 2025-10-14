class Solution {
public:
    bool hasIncreasingSubarrays(vector<int>& nums, int k) {

        int n = nums.size();
        vector<int> maxInc(n);
        maxInc[n - 1] = 1;

        for (int i = n - 2; i >= 0; i--) {
            if (nums[i] < nums[i + 1]) {
                maxInc[i] = maxInc[i + 1] + 1;
            } else {
                maxInc[i] = 1;
            }
        }

        for (int i = 0; i <= (n - 2 * k); i++) {
            if (maxInc[i] >= k && maxInc[i + k] >= k) {
                return true;
            }
        }
        return false;
    }
};