class Solution {
public:
    bool decreasingOrder(vector<int>& nums, int l, int r) {
        for (int i = l; i < r; i++) {
            if (nums[i] < nums[i + 1]) {
                return false;
            }
        }

        return true;
    }
    void nextPermutation(vector<int>& nums) {

        int r = nums.size() - 1;
        if (decreasingOrder(nums, 0, r)) {
            sort(nums.begin(), nums.end());
            return;
        }

        for (int i = 1; i <= r; i++) {
            if (decreasingOrder(nums, i, r)) {
                for (int j = r; j >= i; j--) {
                    if (nums[j] > nums[i - 1]) {
                        swap(nums[i - 1], nums[j]);

                        sort(nums.begin() + i, nums.end());
                        return;
                    }
                }
            }
        }
    }
};