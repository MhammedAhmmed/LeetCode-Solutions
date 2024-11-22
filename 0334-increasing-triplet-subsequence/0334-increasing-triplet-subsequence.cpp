class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int n = nums.size();

        vector<bool> lessLeft(n, false), largeRight(n, false);

        int minLeft = nums[0];
        for (int i = 1; i < n; i++) {
            if (minLeft < nums[i]) {
                lessLeft[i] = true;
            } else {
                minLeft = min(minLeft, nums[i]);
            }
        }

        int maxRight = nums[n - 1];

        for (int i = n - 2; i >= 0; i--) {
            if (maxRight > nums[i]) {
                largeRight[i] = true;
            } else {
                maxRight = max(maxRight, nums[i]);
            }
        }

        for (int i = 0; i < n; i++) {
            if (lessLeft[i] && largeRight[i]) {
                return true;
            }
        }

        return false;
    }
};