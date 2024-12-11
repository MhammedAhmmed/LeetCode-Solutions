class Solution {
public:
    int maximumBeauty(vector<int>& nums, int k) {
        int n = nums.size();

        int minE = *min_element(nums.begin(), nums.end());

        if (minE - k < 0) {
            int shift = k - minE;
            for (int i = 0; i < n; i++) {
                nums[i] += shift;
            }
        }

        int maxE = *max_element(nums.begin(), nums.end());

        vector<int> pref(maxE + k + 2, 0);

        for (int i = 0; i < n; i++) {
            pref[nums[i] - k]++;
            pref[nums[i] + k + 1]--;
        }

        for (int i = 1; i < maxE + k + 2; i++) {
            pref[i] += pref[i - 1];
        }

        return *max_element(pref.begin(), pref.end());
    }
};