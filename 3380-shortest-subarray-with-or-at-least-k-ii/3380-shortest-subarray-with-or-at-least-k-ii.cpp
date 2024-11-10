class Solution {
    int calc(vector<int>& bits) {
        int num = 0;
        for (int i = 0; i < 32; i++) {
            if (bits[i]) {
                num += (pow(2, i));
            }
        }
        return num;
    }
    void changeBits(vector<int>& bits, int num, int add) {
        int index = 0;

        while (num) {
            if (num & 1)
                bits[index] += add;

            index++;
            num >>= 1;
        }
    }

public:
    int minimumSubarrayLength(vector<int>& nums, int k) {
        int p1 = 0, p2 = 0, n = nums.size(), pref = 0;

        int res = n;
        bool found = false;
        vector<int> bits(32, 0);

        while (p2 < n) {
            pref |= nums[p2];
            changeBits(bits, nums[p2], 1);

            while (p1 <= p2 && pref >= k) {
                found = true;
                res = min(res, p2 - p1 + 1);
                changeBits(bits, nums[p1], -1);

                pref = calc(bits);

                p1++;
            }

            p2++;
        }

        if (!found)
            return -1;

        return res;
    }
};