class Solution {
public:
    int minimumMountainRemovals(vector<int>& nums) {
        int n = nums.size();

        vector<int> leftIncreasing(n, 1);
        vector<int> rightIncreasing(n, 1);

        for (int i = 1; i < n; i++) {
            for (int j = 0; j < i; j++) {
                if (nums[i] > nums[j]) {
                    leftIncreasing[i] =
                        max(leftIncreasing[i], leftIncreasing[j] + 1);
                }
            }
        }

        for (int i = n - 2; i >= 0; i--) {
            for (int j = n - 1; j > i; j--) {
                if (nums[i] > nums[j]) {
                    rightIncreasing[i] =
                        max(rightIncreasing[i], rightIncreasing[j] + 1);
                }
            }
        }

        int res = n;

        for (int i = 1; i < n - 1; i++) {

            int leftRemove = i + 1 - leftIncreasing[i];
            int rightRemove = n - i - rightIncreasing[i];

            if (leftRemove == i || rightRemove == n - i - 1)
                continue;

            res = min(res, leftRemove + rightRemove);
        }

        cout << res << endl;

        return res;
    }
};