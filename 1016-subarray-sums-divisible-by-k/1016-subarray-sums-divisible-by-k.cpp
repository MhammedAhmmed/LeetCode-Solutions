class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        map<int, int> mp;

        mp[0]++;
        int sum = 0, res = 0;
        int n = nums.size();

        for (int i = 0; i < n; i++) {
            sum += nums[i];

            int need = ((sum % k) + k) % k;

            res += mp[need];

            mp[((sum % k) + k) % k]++;
        }

        return res;
    }
};