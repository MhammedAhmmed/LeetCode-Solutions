class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int prev = nums[0] - 1;
        int index = 0;
        int count = 0;
        int n = nums.size();

        for (int i = 0; i < n; i++) {
            if (nums[i] != prev) {
                nums[index] = nums[i];
                prev = nums[i];
                count = 1;
                index++;
            } else {
                if (count == 1) {
                    nums[index] = nums[i];
                    count++;
                    index++;
                }
            }
        }

        return index;
    }
};