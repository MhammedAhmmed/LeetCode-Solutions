class Solution {
public:
    int findSmallestInteger(vector<int>& nums, int value) {

        int n = nums.size();
        unordered_map<int, int> freq;
        for (int i = 0; i < n; i++) {
            freq[((nums[i] % value) + value) % value]++;
        }

        int mex = 0;
        for (int i = 0; i < n; i++) {
            if (freq[i % value] == 0) {
                return mex;
            }
            freq[i % value]--;
            mex++;
        }
        return mex;
    }
};