class Solution {
public:
    int minSwaps(vector<int>& nums) {
        int ones = 0;
        for (int x : nums) {
            if (x)
                ones++;
        }
        for (int i = 0; i < ones; i++)
            nums.push_back(nums[i]);
        
        int groupSize = ones, n = nums.size();
        ones = 0;
        int zeros = 0;
        for (int i = 0; i < groupSize; i++) {
            if (nums[i])
                ones++;
            else
                zeros++;
        }
        
        int res = zeros;
        for (int i = groupSize; i < n; i++) {
            if (nums[i])
                ones++;
            else
                zeros++;
            if (nums[i - groupSize])
                ones--;
            else
                zeros--;

            res = min(res, zeros);
        }
        return res;
    }
};