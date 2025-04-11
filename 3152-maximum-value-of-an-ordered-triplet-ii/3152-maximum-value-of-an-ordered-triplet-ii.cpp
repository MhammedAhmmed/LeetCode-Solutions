class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {

        int n = nums.size();
        vector<int> maxR(n), minR(n);
        vector<int> maxL(n), minL(n);

        maxR[n - 2] = minR[n - 2] = nums[n - 1];
        for (int i = n - 3; i >= 0; i--) {
            maxR[i] = max(maxR[i + 1], nums[i + 1]);
            minR[i] = min(minR[i + 1], nums[i + 1]);
        }

        maxL[1] = minL[1] = nums[0];
        for (int i = 2; i < n; i++) {
            maxL[i] = max(maxL[i - 1], nums[i - 1]);
            minL[i] = min(minL[i - 1], nums[i - 1]);
        }

        long long res = 0;
        for (int i = 1; i < n - 1; i++) {
            long long r1 = (minL[i] - nums[i]) * (long long)minR[i];
            long long r2 = (maxL[i] - nums[i]) * (long long)maxR[i];

            res = max(res, max(r1, r2));
        }

        return res;
    }
};