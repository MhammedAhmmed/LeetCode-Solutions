class Solution {
    bool isOn(int num, int index) { return (num >> index) & 1; }
    bool validSubset(vector<int>& nums, int n, int num, int maxOrNum) {
        int maxNumber = 0;

        for (int i = 0; i < n; i++) {
            if (isOn(num, i)) {
                maxNumber |= nums[i];
            }
        }

        return maxNumber == maxOrNum;
    }

public:
    int countMaxOrSubsets(vector<int>& nums) {
        int maxOrNum = 0;

        for (int num : nums) {
            maxOrNum |= num;
        }

        int n = nums.size();
        int numOfsubsets = pow(2, n) - 1;

        int res = 0;
        for (int i = 1; i <= numOfsubsets; i++) {
            if (validSubset(nums, n, i, maxOrNum))
                res++;
        }

        return res;
    }
};