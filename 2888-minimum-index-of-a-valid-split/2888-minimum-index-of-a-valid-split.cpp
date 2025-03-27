class Solution {
public:
    int minimumIndex(vector<int>& nums) {

        int n = nums.size();
        unordered_map<int, int> freq;
        for (int num : nums) {
            freq[num]++;
        }

        int dominant = nums[0];
        int dominantF = freq[nums[0]];
        for (auto f : freq) {
            if (f.second > dominantF) {
                dominantF = f.second;
                dominant = f.first;
            }
        }

        int domBF = 0, domAF = dominantF;

        for (int i = 0; i < n; i++) {
            if (nums[i] == dominant) {
                domBF++;
                domAF--;
            }

            if (domBF >= ((i + 1) / 2 + 1) && domAF >= ((n - i - 1) / 2 + 1)) {
                return i;
            }
        }
        return -1;
    }
};