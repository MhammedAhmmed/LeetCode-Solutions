class Solution {
public:
    int numOfOnes(int x) {
        int res = 0;
        while (x) {
            if (x & 1) {
                res++;
            }
            x >>= 1;
        }
        return res;
    }
    bool canSortArray(vector<int>& nums) {
        map<int, int> mp;

        for (int num : nums) {
            mp[num] = numOfOnes(num);
        }

        int n = nums.size();
        if (n == 1)
            return true;

        while (true) {
            bool change = false;

            for (int i = 1; i < n; i++) {
                if (nums[i] < nums[i - 1] && mp[nums[i]] != mp[nums[i - 1]]) {
                    return false;
                }

                if (nums[i] < nums[i - 1]) {
                    int temp = nums[i - 1];
                    nums[i - 1] = nums[i];
                    nums[i] = temp;

                    change = true;
                }
            }

            if (!change)
                break;
        }
        return true;
    }
};