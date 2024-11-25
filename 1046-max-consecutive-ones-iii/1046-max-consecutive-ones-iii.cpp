class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int n = nums.size();

        int p1 = 0, p2 = 0;

        int res = 0, num0 = 0;

        while (p2 < n) {
            if (nums[p2] == 0) {
                num0++;
            }

            if (num0 > k) {
                while (num0 > k) {
                    if (nums[p1] == 0) {
                        num0--;
                    }
                    p1++;
                }
            }

            res = max(res, p2 - p1 + 1);
            p2++;
        }

        return res;
    }
};