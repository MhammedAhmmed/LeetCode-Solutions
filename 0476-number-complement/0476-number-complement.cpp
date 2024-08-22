class Solution {
bool isOn(int num, int i) {
	return (num >> i) & 1;
}
public:
    int findComplement(int num) {
        int len = floor(log2(num)) + 1;
        int res = 0;
        for (int i = 0; i < len; i++) {
            if (!isOn(num, i)) {
                res += pow(2, i);
            }
        }
        return res;
    }
};