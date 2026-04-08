class Solution {
public:
    int xorAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        int MOD = 1e9 + 7;

        for (vector<int> query : queries) {
            int l = query[0];
            int r = query[1];
            int k = query[2];
            int v = query[3];

            int idx = l;
            while (idx <= r) {
                nums[idx] = ((long long)nums[idx] * v) % MOD;
                idx += k;
            }
        }

        int res = 0;
        for (int x : nums) {
            res ^= x;
        }
        return res;
    }
}
;