class Solution {

    int targetSum(vector<int>& nums, int target, int p, int n, int sum) {
        if (p >= n) {
            if (sum == target) {
                return 1;
            }
            return 0;
        }

        int res = 0;

        res += targetSum(nums, target, p + 1, n, sum + nums[p]);
        res += targetSum(nums, target, p + 1, n, sum - nums[p]);

        return res;
    }

public:
    int findTargetSumWays(vector<int>& nums, int target) {

        return targetSum(nums, target, 0, nums.size(), 0);
    }
};