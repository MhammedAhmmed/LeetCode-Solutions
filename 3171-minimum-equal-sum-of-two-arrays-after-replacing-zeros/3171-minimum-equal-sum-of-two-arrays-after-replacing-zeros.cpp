class Solution {
public:
    long long minSum(vector<int>& nums1, vector<int>& nums2) {

        long long sum1 = 0, sum2 = 0;
        int zeros1 = 0, zeros2 = 0;

        for (int num : nums1) {
            sum1 += num;

            if (num == 0) {
                zeros1++;
            }
        }
        for (int num : nums2) {
            sum2 += num;

            if (num == 0) {
                zeros2++;
            }
        }

        if (zeros1 == 0 && zeros2 == 0) {
            if (sum1 == sum2) {
                return sum1;
            }
            return -1;
        }

        if (zeros1 == 0 && zeros2 != 0) {
            if (sum2 + zeros2 <= sum1) {
                return sum1;
            }
            return -1;
        }

        if (zeros1 != 0 && zeros2 == 0) {
            if (sum1 + zeros1 <= sum2) {
                return sum2;
            }
            return -1;
        }

        return max(sum1 + zeros1, sum2 + zeros2);
    }
};