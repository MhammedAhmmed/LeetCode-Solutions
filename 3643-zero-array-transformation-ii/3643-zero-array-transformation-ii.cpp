class Solution {
    bool isEnough(vector<int>& nums, vector<vector<int>>& queries, int mid) {

        int n = nums.size();
        vector<int> prefix(n + 1, 0);

        for (int i = 0; i <= mid; i++) {
            int l = queries[i][0];
            int r = queries[i][1];
            int val = queries[i][2];

            prefix[l] -= val;
            prefix[r + 1] += val;
        }

        for (int i = 1; i < n; i++) {
            prefix[i] += prefix[i - 1];
        }

        for (int i = 0; i < n; i++) {
            if (nums[i] + prefix[i] > 0) {
                return false;
            }
        }

        return true;
    }

public:
    int minZeroArray(vector<int>& nums, vector<vector<int>>& queries) {

        if (isEnough(nums, queries, -1)) {
            return 0;
        }

        int res = -1;
        int l = 0, r = queries.size() - 1, mid;
        while (l <= r) {
            mid = (l + r) / 2;

            if (isEnough(nums, queries, mid)) {
                res = mid + 1;
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }

        return res;
    }
};