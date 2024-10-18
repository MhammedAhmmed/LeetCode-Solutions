class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int res = 0;

        map<int, int> pref;
        pref[0]++;

        int n = nums.size(), sum = 0;

        for (int i = 0; i < n; i++) {
            sum += nums[i];

            int need = sum - k;

            res += pref[need];

            pref[sum]++;
        }

        return res;
    }
};