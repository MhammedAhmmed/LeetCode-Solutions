class Solution {
    int maxUpperIndex(vector<int>& nums, int num, int upper, int l, int r) {

        int mid, res = -1;

        while (l <= r) {
            mid = (l + r) / 2;

            if (num + nums[mid] <= upper) {
                res = mid;
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }

        return res;
    }
    int maxLowerIndex(vector<int>& nums, int num, int lower, int l, int r) {

        int mid, res = -1;

        while (l <= r) {
            mid = (l + r) / 2;

            if (num + nums[mid] >= lower) {
                res = mid;
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }

        return res;
    }

public:
    long long countFairPairs(vector<int>& nums, int lower, int upper) {
        sort(nums.begin(), nums.end());

        long long res = 0;
        int n = nums.size();

        for (int i = 0; i < n; i++) {
            int maxIndexUpper =
                maxUpperIndex(nums, nums[i], upper, i + 1, n - 1);
            int maxIndexLower =
                maxLowerIndex(nums, nums[i], lower, i + 1, n - 1);

            if (maxIndexUpper == -1 || maxIndexLower == -1)
                continue;

            res += (maxIndexUpper - maxIndexLower + 1);
        }

        return res;
    }
};