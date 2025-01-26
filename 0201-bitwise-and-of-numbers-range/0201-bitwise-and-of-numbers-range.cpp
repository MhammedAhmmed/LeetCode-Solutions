class Solution {
    bool isOn(int num, int index) { return (num >> index) & 1; }
    int setOne(int num, int index) {
        int temp = 1;
        temp = temp << index;
        return num | temp;
    }

public:
    int rangeBitwiseAnd(int left, int right) {
        int res = 0;

        int len = 32;
        for (int i = 0; i < len; i++) {
            int power = pow(2, i) - 1;

            if (right - left <= power) {
                if (isOn(left, i) && isOn(right, i)) {
                    res = setOne(res, i);
                }
            }
        }

        return res;
    }
};