class Solution {
public:
    vector<int> getMaximumXor(vector<int>& nums, int maximumBit) {
        int sum = 0;
        int n = nums.size();

        for (int i = 0; i < n; i++) {
            sum ^= nums[i];
        }

        int maxK = pow(2, maximumBit) - 1;

        vector<int> res(n);

        for (int i = n - 1; i >= 0; i--) {
            res[n - i - 1] = sum ^ maxK;
            sum ^= nums[i];
        }

        return res;
    }
};