class Solution {
public:
    int minSubarray(vector<int>& nums, int p) {
        map<int, int> mp;
        mp[0] = -1;

        long long totalsum = 0;
        for (int x : nums) {
            totalsum += x;
        }

        int rem = totalsum % p;
        if (rem == 0)
            return 0;

        int n = nums.size();
        int res = n;
        long long sum = 0;
        for (int i = 0; i < n; i++) {
            sum += nums[i];

            int need = (((sum % p) - rem) + p) % p;

            if (mp.find(need) != mp.end()) {
                res = min(res, i - mp[need]);
            }
            mp[sum % p] = i;
        }

        if (res == n)
            return -1;
        return res;
    }
};