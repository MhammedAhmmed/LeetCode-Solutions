class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int l = 0, r = nums.size() - 1, n = nums.size(), mid, res = 0;

        while (l <= r) {
            mid = (l + r) / 2;

            if (mid > 0 && nums[mid] == nums[mid - 1]) {
                if (mid & 1) {
                    l = mid + 1;
                }
                else {
                    r = mid - 2;
                }
            }
            else if (mid < n - 1 && nums[mid] == nums[mid + 1]) {
                if (mid & 1)
                    r = mid - 1;
                else
                    l = mid + 2;
            }
            else {
                res = nums[mid];
                break;
            }
        }
        return res;
    }
};