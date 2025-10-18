class Solution {
public:
    int maxDistinctElements(vector<int>& nums, int k) {

        sort(nums.begin(), nums.end());
        int n = nums.size();
        int largest = nums[n - 1] + k;
        int res = 0;
        for (int i = n - 1; i >= 0; i--) {
            if (largest >= (nums[i] - k) && largest <= (nums[i] + k)) {
                res++;
                largest--;
            } else if (largest > nums[i] + k) {
                res++;
                largest = nums[i] + k - 1;
            }
        }

        return res;
    }
};