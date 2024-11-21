class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        int l = 0, r = nums.size() - 1;
        sort(nums.begin(), nums.end());
        int res = 0;

        while (l < r) {
            if (nums[l] + nums[r] == k) {
                l++;
                r--;
                res++;
            } else if (nums[l] + nums[r] < k) {
                l++;
            } else {
                r--;
            }
        }
        return res;
    }
};