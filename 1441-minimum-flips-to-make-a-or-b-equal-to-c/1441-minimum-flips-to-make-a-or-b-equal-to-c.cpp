class Solution {
    bool isOn(int num, int index) { return (num >> index) & 1; }

public:
    int minFlips(int a, int b, int c) {
        int res = 0;

        int len = 32;
        for (int i = 0; i < len; i++) {
            int aNum = isOn(a, i);
            int bNum = isOn(b, i);
            int cNum = isOn(c, i);

            if (cNum) {
                if (aNum + bNum == 0) {
                    res++;
                }
            } else {
                res += aNum + bNum;
            }
        }

        return res;
    }
};