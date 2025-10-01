class Solution {
public:
    int triangleNumber(vector<int>& nums) {

        sort(nums.begin(), nums.end());
        int n = nums.size();
        int res = 0;
        for (int i = 0; i < n - 2; i++) {
            for (int j = i + 1; j < n - 1; j++) {
                int twoSide = nums[i] + nums[j];
                if (twoSide <= nums[j + 1]) {
                    continue;
                }

                int l = j + 1, r = n - 1, mid;
                int index = l;
                while (l <= r) {
                    mid = (l + r) / 2;
                    if (twoSide > nums[mid]) {
                        index = mid;
                        l = mid + 1;
                    } else {
                        r = mid - 1;
                    }
                }

                res += (index - j);
            }
        }

        return res;
    }
};