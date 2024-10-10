class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int p1 = 0, p2 = nums.size() - 1;

        int k = 0;
        while (p1 <= p2) {
            if (nums[p1] == val && nums[p2] != val) {
                int temp = nums[p1];
                nums[p1] = nums[p2];
                nums[p2] = temp;
                p1++;
                p2--;
                k++;
            } else if (nums[p1] != val) {
                k++;
                p1++;
            } else {
                p2--;
            }
        }

        for (int x : nums) {
            cout << x << " ";
        }
        return k;
    }
};