class Solution {
public:
    bool check(vector<int>& nums) {
        int n = nums.size();
        int minElement = nums[0], pos = 0;

        for (int i = 1; i < n; i++) {
            if (nums[i] < minElement) {
                minElement = nums[i];
                pos = i;
            }
            if (nums[i] == minElement) {
                if (nums[i - 1] > nums[i]) {
                    pos = i;
                }
            }
        }

        for (int i = pos; i < n + pos - 1; i++) {
            if (nums[(i + 1) % n] < nums[i % n]) {
                return false;
            }
        }

        return true;
    }
};