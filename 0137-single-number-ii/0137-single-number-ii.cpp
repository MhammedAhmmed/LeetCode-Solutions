class Solution {
    bool isOn(int num, int index) { return (num >> index) & 1; }
    int setOne(int num, int index) {
        int temp = 1;
        temp = temp << index;
        return num | temp;
    }

public:
    int singleNumber(vector<int>& nums) {
        int n = nums.size(), len = 32;
        vector<int> bitFreq(len, 0);

        for (int num : nums) {
            for (int i = 0; i < len; i++) {
                if (isOn(num, i)) {
                    bitFreq[i]++;
                }
            }
        }

        int res = 0;

        for (int i = 0; i < len; i++) {
            if (bitFreq[i] % 3 != 0) {
                res = setOne(res, i);
            }
        }

        return res;
    }
};