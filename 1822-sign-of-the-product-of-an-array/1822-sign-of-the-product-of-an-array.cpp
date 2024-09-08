class Solution {
public:
    int arraySign(vector<int>& nums) {
        int neg = 0, zeros = 0;

        for (int num : nums) {
            if (num == 0)
                zeros++;
            if (num < 0)
                neg++;
        }
        if (zeros)
            return 0;
        else if (neg & 1)
            return -1;
        return 1;
    }
};