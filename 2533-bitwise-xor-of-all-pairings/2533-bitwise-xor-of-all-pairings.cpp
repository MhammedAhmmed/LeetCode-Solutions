class Solution {
public:
    int xorAllNums(vector<int>& nums1, vector<int>& nums2) {
        int n2 = nums2.size();

        int nums2Xor = 0;
        for (int x : nums2) {
            nums2Xor ^= x;
        }

        int res = 0;

        for (int x : nums1) {
            if (n2 & 1) {
                res ^= (x ^ nums2Xor);
            } else {
                res ^= nums2Xor;
            }
        }

        return res;
    }
};