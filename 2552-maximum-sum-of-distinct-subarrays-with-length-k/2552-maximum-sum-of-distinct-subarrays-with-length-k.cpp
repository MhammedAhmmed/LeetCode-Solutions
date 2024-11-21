class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        long long res = 0, tempRes = 0;

        int p1 = 0, p2 = 0, n = nums.size();
        map<int, int> freq;

        while (p2 < n) {
            tempRes += nums[p2];
            freq[nums[p2]]++;

            while (freq[nums[p2]] > 1) {
                tempRes -= nums[p1];
                freq[nums[p1]]--;

                p1++;
            }

            if (p2 - p1 + 1 == k) {
                res = max(res, tempRes);

                tempRes -= nums[p1];
                freq[nums[p1]]--;
                p1++;
            }

            p2++;
        }

        return res;
    }
};