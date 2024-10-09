class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();

        int pos = 1;

        for (int i = 0; i < n - 1; i++) {
            if (nums[i] != nums[i + 1]) {
                nums[pos] = nums[i + 1];
                pos++;
            }
        }

        for (int i = 0; i < n; i++) {
            cout << nums[i] << " ";
        }
        return pos;
    }
};