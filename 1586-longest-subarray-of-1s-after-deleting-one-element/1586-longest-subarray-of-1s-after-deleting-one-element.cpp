class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int p1 = 0, p2 = 0, n0 = 0;

        int n = nums.size();
        int res = 0;
        while (p2 < n) {
            if (nums[p2] == 0) {
                n0++;
            }
            while (n0 > 1) {
                if (nums[p1] == 0) {
                    n0--;
                }

                p1++;
            }
            if (n0 > 0) {
                res = max(res, p2 - p1);
            } else {
                res = max(res, p2 - p1 + 1);
            }
            p2++;
        }

        return res == n ? res - 1 : res;
    }
};